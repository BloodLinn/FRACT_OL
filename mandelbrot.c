/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:37:09 by aokur             #+#    #+#             */
/*   Updated: 2025/12/01 14:30:31 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(double *re, double *im)
{
	int			i;
	double		zr;
	double		zi;
	double		zr_tmp;
	double		zi_tmp;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < MAX_ITER && (zr * zr + zi * zi) <= 4.0)
	{
		zr_tmp = (zr * zr) - (zi * zi);
		zi_tmp = (2 * zr * zi);
		zr = zr_tmp + *re;
		zi = zi_tmp + *im;
		i++;
	}
	return (i);
}

static	int	color_iter(int iter)
{
	int		color;
	double	t;
	int		shade;

	if (iter == MAX_ITER)
		color = 0x00FFFF;
	else
	{
		t = (double)iter / MAX_ITER;
		shade = (int)(255.0 * t);
		color = (shade << 16) | (shade << 8) | shade;
	}
	return (color);
}

void	render_mandelbrot(t_fractol *f)
{
	t_render	*a;
	double		iter;
	double		color;

	a->x = 0;
	while (a->x < f->width)
	{
		a->y = 0;
		while (a->y < f->height)
		{
			complexip(a->x, a->y, &a->re, &a->im, f);
			iter = mandelbrot_iter(&a->re, &a->im);
			color = color_iter(iter);
			ft_put_pixel(a->x, a->y, a->color, f);
			a->y++;
		}
		a->x++;
	}
}
