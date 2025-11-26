/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:06:21 by aokur             #+#    #+#             */
/*   Updated: 2025/11/26 06:32:49 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main()
{
	t_fractol	f;

	init_fractol(&f);
	render_mandelbrot(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_hook(f.win, 2, 1, key_handler, &f);
	mlx_loop(f.mlx);
	return (0);
}