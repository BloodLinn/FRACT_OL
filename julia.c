/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:49:40 by aokur             #+#    #+#             */
/*   Updated: 2025/12/02 21:55:06 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_iter(t_fractol *f, double x, double y)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	zx = x;
	zy = y;
	i = 0;
	while (i < f->max_iter && (zx * zx + zy * zy) <= 4.0)
	{
		tmp = zx * zx - zy * zy + f->c_re;
		zy = 2 * zx * zy + f->c_im;
		zx = tmp;
		i++;
	}
	return (i);
}

void	render_julia(t_fractol *f)
{
	int		x;
	int		y;
	double	re;
	double	im;
	int		iter;

	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			re = (x - f->width / 2.0) * (4.0 / f->width) / f->zoom + f->shift_x;
			im = (y - f->height / 2.0) * (4.0 / f->height) / f->zoom + f->shift_y;
			iter = julia_iter(f, re, im);
			my_put_pixel(&f->img, x, y, get_color(iter, f->max_iter));
			x++;
		}
		y++;
	}
}
