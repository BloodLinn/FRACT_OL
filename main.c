/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:06:21 by aokur             #+#    #+#             */
/*   Updated: 2025/11/24 21:56:25 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main()
{
	t_fractol	f;

	init_fractol(&f);
	mlx_hook(f.win, 17, 0, close_window,&f);
	mlx_hook(f.win, 2, 1, key_handler,&f);
	fill_background(0xFFFFF, &f);
	ft_draw_cross(0x000000, &f);
	ft_draw_square_outline(0x000000, &f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
	mlx_loop(f.mlx);
	return (0);
}