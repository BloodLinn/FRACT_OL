/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:37:09 by aokur             #+#    #+#             */
/*   Updated: 2025/12/03 15:28:42 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot_iter(t_fractol *f, double *re, double *im)
{
	int			i;
	double		zr;
	double		zi;
	double		zr_tmp;
	double		zi_tmp;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < f->max_iter && (zr * zr + zi * zi) <= 4.0)
	{
		zr_tmp = (zr * zr) - (zi * zi);
		zi_tmp = (2 * zr * zi);
		zr = zr_tmp + *re;
		zi = zi_tmp + *im;
		i++;
	}
	return (i);
}

int	color_iter(t_fractol *f, int iter)
{
	int		color;
	double	t;
	int		shade;

	if (iter == f->max_iter)
		return (0x000000);
	if (f->color_mode == 1)
		return (color_fire(f, iter));
	if (f->color_mode == 2)
		return (color_ocean(f, iter));
	if (f->color_mode == 3)
		return (color_bands(f, iter));
	t = (double)iter / f->max_iter;
	shade = (int)(255.0 * t);
	color = (shade << 16) | (shade << 8) | shade;
	return (color);
}

void	render_mandelbrot(t_fractol *f)
{
	t_render	a;
	int			iter;
	int			color;

	a.x = 0;
	while (a.x < f->width)
	{
		a.y = 0;
		while (a.y < f->height)
		{
			complexip(&a.re, &a.im, f, a);
			iter = mandelbrot_iter(f, &a.re, &a.im);
			color = color_iter(f, iter);
			ft_put_pixel(color, f, a);
			a.y++;
		}
		a.x++;
	}
}
