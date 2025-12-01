/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:46:50 by aokur             #+#    #+#             */
/*   Updated: 2025/12/01 13:32:13 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *f)
{
	f->width = WIDTH;
	f->height = HEIGHT;
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit(1);
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->max_iter = MAX_ITER;
	f->win = mlx_new_window(f->mlx, f->width, f->height, "fractol");
	f->img.img = mlx_new_image(f->mlx, f->width, f->height);
	f->img.addr = mlx_get_data_addr(f->img.img,
			&f->img.bpp, &f->img.line_len, &f->img.endian);
}
