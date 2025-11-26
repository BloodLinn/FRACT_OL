/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:37:09 by aokur             #+#    #+#             */
/*   Updated: 2025/11/26 06:29:19 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(double re, double im)
{
	t_mandelbrot m;
	int		i;

	m.zr = 0.0;
	m.zi = 0.0;
	i = 0;
	while (i < MAX_ITER && (m.zr * m.zr + m.zi * m.zi) <= 4.0)
	{
		m.zr_tmp = (m.zr * m.zr) - (m.zi * m.zi);
		m.zi_tmp = (2 * m.zr * m.zi);
		m.zr = m.zr_tmp + re;
		m.zi = m.zi_tmp + im;
		i++;
	}
	return (i);
}

static	int	color_iter(int color, int iter)
{
	if (iter == MAX_ITER)
		color = 0x00FFFF;
	else
	{
		double t = (double)iter / MAX_ITER;
		int shade = (int)(255.0 * t);
		color = (shade << 18) | (shade << 9) | shade;
	}
	return (color);
}

void	render_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;
	int		color;
	double	re;
	double	im;

	x = 0;
	while(x < f->width)
	{
		y = 0;
		while (y < f->height)
		{
			complexip(x, y, &re, &im , f);
			iter = mandelbrot_iter(re, im);
			color = color_iter(color, iter);
			ft_put_pixel(x, y, color, f);
			y++;
		}
		x++;
	}
}
