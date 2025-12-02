/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:00:47 by aokur             #+#    #+#             */
/*   Updated: 2025/12/02 22:15:37 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("  ./fractol mandelbrot\n", 2);
	ft_putstr_fd("  ./fractol julia <c_re> <c_im>\n", 2);
	exit(1);
}

int	choice_fractal(int ac, char **av, t_fractol *f)
{
	if (ac != 2)
		print_usage();
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		f->name = "mandelbrot";
		init_fractol(f);
		render_mandelbrot(f);
	}
	else if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		f->name = "julia";
		init_fractol(f);
		f->c_re = -0.4;
		f->c_im = 0.6;
		render_julia(f);
	}
	else
		print_usage();
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	mlx_hook(f->win, 4, 1 << 2, mouse_handler, f);
	mlx_hook(f->win, 17, 0, close_window, f);
	mlx_hook(f->win, 2, 1, key_handler, f);
	mlx_loop(f->mlx);
	return (0);
}
