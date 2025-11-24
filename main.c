/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:06:21 by aokur             #+#    #+#             */
/*   Updated: 2025/11/24 18:52:13 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
	t_fractol	f;

	init_fractol(&f);
	mlx_hook(f.win, 17, 0, close_window,&f);
	mlx_hook(f.win, 2, 1, key_handler,&f);
	ft_put_pixel(&f,400, 400, 0XFFFFFF);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
	mlx_loop(f.mlx);
	return (0);
}