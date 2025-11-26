/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:23:37 by aokur             #+#    #+#             */
/*   Updated: 2025/11/26 06:58:17 by aokur            ###   ########.fr       */
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
	*re = (x - f->width / 2.0) / (0.5 * f->zoom * f->width) + f->shift_x;
	*im = (y - f->height / 2.0) / (0.5 * f->zoom * f->height) + f->shift_y;
}
