/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:00:47 by aokur             #+#    #+#             */
/*   Updated: 2025/12/02 22:28:29 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	run_mandelbrot(t_fractol *f);
static void	run_julia(int ac, char **av, t_fractol *f);
void	print_usage(void)
{
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("  ./fractol mandelbrot\n", 2);
	ft_putstr_fd("  ./fractol julia\n", 2);
	ft_putstr_fd("  ./fractol julia <c_re> <c_im>\n", 2);
	exit(1);
}


int	choice_fractal(int ac, char **av, t_fractol *f)
{
	if (ac < 2)
		print_usage();
	if (!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2)
		ren_mandelbrot(f);
	else if (!ft_strncmp(av[1], "julia", 5) && (ac == 2 || ac == 4))
		run_julia(ac, av, f);
	else
		print_usage();
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	mlx_hook(f->win, 4, 1 << 2, mouse_handler, f);
	mlx_hook(f->win, 17, 0, close_window, f);
	mlx_hook(f->win, 2, 1, key_handler, f);
	mlx_loop(f->mlx);
	return (0);
}

static void	run_mandelbrot(t_fractol *f)
{
	f->name = "mandelbrot";
	init_fractol(f);
	render_mandelbrot(f);
}

static void	run_julia(int ac, char **av, t_fractol *f)
{
	f->name = "julia";
	init_fractol(f);
	if (ac == 4)
	{
		f->c_re = ft_atoi(av[2]);
		f->c_im = ft_atoi(av[3]);
	}
	else
	{
		f->c_re = -0.4;
		f->c_im = 0.6;
	}
	render_julia(f);
}
