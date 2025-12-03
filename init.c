/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:46:50 by aokur             #+#    #+#             */
/*   Updated: 2025/12/03 15:07:38 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *f)
{
	f->width = WIDTH;
	f->height = HEIGHT;
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit(1);
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->max_iter = MAX_ITER;
	f->color_mode = 0;
	f->win = mlx_new_window(f->mlx, f->width, f->height, "fractol");
	f->img.img = mlx_new_image(f->mlx, f->width, f->height);
	f->img.addr = mlx_get_data_addr(f->img.img,
			&f->img.bpp, &f->img.line_len, &f->img.endian);
}

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static double	is_sign(const char **s)
{
	double	sign;

	sign = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

double	ft_atod(const char *str)
{
	t_atod	a;

	a.sign = 1;
	a.intp = 0;
	a.frac = 0;
	a.div = 1;
	while (is_space(*str))
		str++;
	a.sign = is_sign(&str);
	while (is_digit(*str))
	{
		a.intp = a.intp * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			a.frac = a.frac * 10 + (*str - '0');
			a.div *= 10;
			str++;
		}
	}
	return (a.sign * (a.intp + a.frac / a.div));
}
