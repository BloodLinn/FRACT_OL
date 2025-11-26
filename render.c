/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:23:37 by aokur             #+#    #+#             */
/*   Updated: 2025/11/26 06:20:58 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_put_pixel(int x, int y, int color, t_fractol *f)
{
	char	*pixel;
	pixel = f->img.addr + (y * f->img.line_len)
			+ (x * ((f->img.bpp) / 8));
	*(unsigned int *)pixel = color;
	return(pixel);
}

void	complexip(int x, int y, double *re, double *im, t_fractol *f)
{
	t_pixelpmoc	p;

	p.min_re = -2.0;
	p.max_re = 1.0;
	p.min_im = -1.5;
	p.max_im = 1.5;
	p.re_range = p.max_re - p.min_re;
	p.im_range = p.max_im - p.min_im;
	p.xs = (double)x / f->width;
	p.ys = (double)y / f->height;
	*re = p.min_re + p.xs * p.re_range;
	*im = p.min_im + p.ys * p.im_range;
}
