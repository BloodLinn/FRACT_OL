/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:49:40 by aokur             #+#    #+#             */
/*   Updated: 2025/12/03 13:39:02 by aokur            ###   ########.fr       */
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
	t_render	a;
	double		color;
	int			iter;

	a.y = 0;
	a.tmp.re_range = (a.x - f->width / 2.0) * (4.0 / f->width)
		/ f->zoom + f->shift_x;
	a.tmp.im_range = (a.y - f->height / 2.0) * (4.0 / f->height)
		/ f->zoom + f->shift_y;
	while (a.y < f->height)
	{
		a.x = 0;
		while (a.x < f->width)
		{
			a.re = a.tmp.re_range;
			a.im = a.tmp.im_range;
			iter = julia_iter(f, a.re, a.im);
			color = color_iter(f, iter);
			ft_put_pixel(color, f, a);
			a.x++;
		}
		a.y++;
	}
}
