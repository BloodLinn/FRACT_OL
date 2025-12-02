/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:06:21 by aokur             #+#    #+#             */
/*   Updated: 2025/12/02 21:56:26 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main (int ac, char **av)
{
	t_fractol	f;
	if(ac == 2)
	{
		if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		{
			f.name = "mandelbrot";
			init_fractol (&f);
			render_mandelbrot (&f);
			mlx_put_image_to_window (f.mlx, f.win, f.img.img, 0, 0);
			mlx_hook (f.win, 4, 1 << 2, mouse_handler, &f);
			mlx_hook (f.win, 17, 0, close_window, &f);
			mlx_hook (f.win, 2, 1, key_handler, &f);
			mlx_loop (f.mlx);
		}
		else if (ft_strncmp(av[1], "julia", 5) == 0)
		{
			f.name = "julia";
			init_fractol (&f);
			f.c_re = -0.4;
			f.c_im = 0.6;
			render_julia(&f);
			mlx_put_image_to_window (f.mlx, f.win, f.img.img, 0, 0);
			mlx_hook (f.win, 4, 1 << 2, mouse_handler, &f);
			mlx_hook (f.win, 17, 0, close_window, &f);
			mlx_hook (f.win, 2, 1, key_handler, &f);
			mlx_loop (f.mlx);
		}
		else
		{
			ft_putstr_fd("Error: Invalid Name", 2);
			return (0);
		}
	}
	ft_putstr_fd("Error: Argüman Eksik", 2);
	return (0);
}
