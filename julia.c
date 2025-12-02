/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:49:40 by aokur             #+#    #+#             */
/*   Updated: 2025/12/02 22:18:12 by aokur            ###   ########.fr       */
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
	t_render a;
	double	color;
	int		iter;

	a.y = 0;
	while (a.y < f->height)
	{
		a.x = 0;
		while (a.x < f->width)
		{
			a.re = (a.x - f->width / 2.0) * (4.0 / f->width) / f->zoom + f->shift_x;
			a.im = (a.y - f->height / 2.0) * (4.0 / f->height) / f->zoom + f->shift_y;
			iter = julia_iter(f, a.re, a.im);
			color = color_iter(f, iter);
			ft_put_pixel(a.x, a.y, color, f);
			a.x++;
		}
		a.y++;
	}
}
