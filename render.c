/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:23:37 by aokur             #+#    #+#             */
/*   Updated: 2025/11/24 19:08:07 by aokur            ###   ########.fr       */
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

//void	ft_put_pixel(t_fractol *f, int x, int y, int color)
//{
//	char *pixel;

//	if (x < 0 || x >= f->width || y < 0 || y >= f->height)
//		return;


//	pixel = f->img.addr + (y * f->img.line_len) + (x * (f->img.bpp / 8));
//	*(unsigned int *)pixel = color;
//}

//void	ft_center_box(int color ,t_fractol *f)
//{
//	int x;
//	int y;
//	char	*pixel;
//	int bytepp = f->img.bpp / 8;

//	x = (f->width / 2) - 10;
//	while(x < (f->width / 2) + 10)
//	{
//		y = (f->height / 2) - 10;
//		while(y < (f->height / 2) + 10)
//		{
//			pixel = f->img.addr + (y * f->img.line_len) + (x * bytepp);
//			*(unsigned int *)pixel = color;
//			y++;
//		}
//		x++;
//	}

//}