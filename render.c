/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:23:37 by aokur             #+#    #+#             */
/*   Updated: 2025/11/24 21:57:19 by aokur            ###   ########.fr       */
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
	int cx = (f->width / 2) - 5;
	int cy = (f->height / 2) - 5;
	int bytepp = f->img.bpp / 8;
	char	*pixel;

	while(cx <= (f->width / 2) + 5)
	{
		pixel = f->img.addr + (cy * f->img.line_len) + (cx * bytepp);
		*(unsigned int *)pixel = color;
		cx++;
		cy++;
	}
	cx = (f->width / 2) + 5;
	cy = (f->height / 2) - 5;
	while(cy <= (f->height / 2) + 5)
	{
		pixel = f->img.addr + (cy * f->img.line_len) + (cx * bytepp);
		*(unsigned int *)pixel = color;
		cx--;
		cy++;
	}
}

//static void	ft_draw_square_fill(int color, t_fractol *f)
//{
	//	t_kolay a;
	//	a.cx = f->width / 2;
	//	a.cy = f->height / 2;
	//	a.start_x = a.cx - 10;
	//	a.end_x = a.cx + 10;
	//	a.start_y = a.cy - 10;
	//	a.end_y = a.cy - 10;
	//	int	bytepp = f->img.bpp / 8;
	//	char	*pixel;
	//}

	typedef struct s_kolay
	{
		int cx;
		int cy;
		int start_x;
		int end_x;
		int start_y;
		int end_y;
		int bytepp;
		char *pixel;
	} t_kolay;
	
void	ft_draw_square_outline(int color, t_fractol *f)
{
	t_kolay a;
	
	a.cx = f->width / 2;
	a.cy = f->height / 2;
	a.start_x = a.cx - 10;
	a.end_x = a.cx + 10;
	a.start_y = a.cy - 10;
	a.end_y = a.cy - 10;
	int	bytepp = f->img.bpp / 8;
	char	*pixel;

	while(a.start_x >= a.end_x)
	{
		pixel = f->img.addr + (a.start_y * f->img.line_len) + (a.start_x * bytepp);
		*(unsigned int *)pixel = color;
		a.end_x--;
	}
	
}