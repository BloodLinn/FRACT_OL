/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:23:37 by aokur             #+#    #+#             */
/*   Updated: 2025/12/03 13:40:36 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_put_pixel(int color, t_fractol *f, t_render a)
{
	char	*pixel;

	pixel = f->img.addr + (a.y * f->img.line_len)
		+ (a.x * ((f->img.bpp) / 8));
	*(unsigned int *) pixel = color;
	return (pixel);
}

void	complexip(double *re, double *im, t_fractol *f, t_render a)
{
	*re = (a.x - f->width / 2.0) / (0.5 * f->zoom * f->width) + f->shift_x;
	*im = (a.y - f->height / 2.0) / (0.5 * f->zoom * f->height) + f->shift_y;
}

void	render_fractol(t_fractol *f)
{
	if (!ft_strncmp(f->name, "mandelbrot", 10))
		render_mandelbrot(f);
	else if (!ft_strncmp(f->name, "julia", 5))
		render_julia(f);
}
