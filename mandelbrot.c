/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:37:09 by aokur             #+#    #+#             */
/*   Updated: 2025/11/26 05:23:57 by aokur            ###   ########.fr       */
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

void	render_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;
	double	re;
	double	im;
	char	*pixel;

	x = 0;
	while(x < f->width)
	{
		y = 0;
		while (y < f->height)
		{
			complexip(x, y, &re, &im , f);
			iter = mandelbrot_iter(re, im);
			color =
			ft_put_pixel(x, y, pixel, color, &f);
			y++;
		}
		x++;
	}
}