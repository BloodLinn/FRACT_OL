/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:29:20 by aokur             #+#    #+#             */
/*   Updated: 2025/11/26 07:15:50 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		close_window(f);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == 4)
		f->zoom *= 1.1;
	if (button == 5)
		f->zoom *= 0.9;
	render_mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}
