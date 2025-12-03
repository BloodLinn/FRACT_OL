/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:29:20 by aokur             #+#    #+#             */
/*   Updated: 2025/12/03 15:09:41 by aokur            ###   ########.fr       */
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
	double	move;

	move = 0.1 / f->zoom;
	if (keycode == 65307)
		close_window(f);
	if (keycode == 65361)
		f->shift_x -= move;
	if (keycode == 65363)
		f->shift_x += move;
	if (keycode == 65362)
		f->shift_y -= move;
	if (keycode == 65364)
		f->shift_y += move;
	if (keycode == 49)
		f->color_mode = 1;
	if (keycode == 50)
		f->color_mode = 2;
	if (keycode == 51)
		f->color_mode = 3;
	render_fractol(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == 4)
		f->zoom *= 1.1;
	if (button == 5)
		f->zoom /= 1.1;
	render_fractol(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}
