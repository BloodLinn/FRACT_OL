/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:23:37 by aokur             #+#    #+#             */
/*   Updated: 2025/11/19 18:27:54 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_background(int color, t_fractol *f)
{
	int		x;
	int		y;
	char	*pixel;

	x = 0;
	while (x < f->width)
	{
		y = 0;
		while (y < f->height)
		{
			pixel = f->img.addr + (y * f->img.line_len)
			+ (x * ((f->img.bpp) / 8));
			*(unsigned int *)pixel = color;
			y++;
		}
		x++;
	}
}
