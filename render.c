/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:23:37 by aokur             #+#    #+#             */
/*   Updated: 2025/11/24 19:43:54 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_background(int color, t_fractol *f)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			pixel = f->img.addr + (y * f->img.line_len)
			+ (x * ((f->img.bpp) / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}

void ft_draw_cross(int color, t_fractol *f)
{
	int cx = (f->width / 2) - 100;
	int cy = (f->height / 2) - 100;
	int bytepp = f->img.bpp / 8;
	char	*pixel;

	while(cx <= (f->width / 2) + 100)
	{
		pixel = f->img.addr + (cy * f->img.line_len) + (cx * bytepp);
		*(unsigned int *)pixel = color;
		cx++;
		cy++;
	}
	cx = (f->width / 2) + 100;
	cy = (f->height / 2) - 100;
	while(cy <= (f->height / 2) + 100)
	{
		pixel = f->img.addr + (cy * f->img.line_len) + (cx * bytepp);
		*(unsigned int *)pixel = color;
		cx--;
		cy++;
	}
}