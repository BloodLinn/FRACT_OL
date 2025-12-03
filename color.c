/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:01:59 by aokur             #+#    #+#             */
/*   Updated: 2025/12/03 15:28:02 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_fire(t_fractol *f, int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == f->max_iter)
		return (0x000000);
	t = (double)iter / f->max_iter;
	r = (int)(255.0 * t);
	g = (int)(128.0 * t);
	b = (int)(64.0 * t);
	return ((r << 16) | (g << 8) | b);
}

int	color_ocean(t_fractol *f, int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == f->max_iter)
		return (0x000020);
	t = (double)iter / f->max_iter;
	r = (int)(20 + 30 * t);
	g = (int)(80 + 150 * t);
	b = (int)(150 + 105 * t);
	return ((r << 16) | (g << 8) | b);
}

int	color_bands(t_fractol *f, int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == f->max_iter)
		return (0x000000);
	t = (double)iter / f->max_iter;
	r = (int)(255 * t);
	g = (int)(255 * t);
	b = 0;
	return ((r << 16) | (g << 8) | b);
}
