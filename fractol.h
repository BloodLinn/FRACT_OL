/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:46:31 by aokur             #+#    #+#             */
/*   Updated: 2025/12/02 22:20:21 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	t_img	img;
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		max_iter;
	char	*name;
	int		type;
	double	c_re;
	double	c_im;
}	t_fractol;

typedef struct s_pixelpmoc
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_range;
	double	im_range;
	double	xs;
	double	ys;
}	t_pixelpmoc;

typedef struct s_render
{
	int		x;
	int		y;
	double		color;
	double	re;
	double	im;
}	t_render;

void	init_fractol(t_fractol *f);
int		key_handler(int keycode, t_fractol *f);
int		mouse_handler(int button, int x, int y, t_fractol *f);
int		close_window(t_fractol *f);
char	*ft_put_pixel(int x, int y, int color, t_fractol *f);
void	complexip(int x, int y, double *re, double *im, t_fractol *f);
int		color_iter(t_fractol *f, int iter);
void	render_fractol(t_fractol *f);
void	render_mandelbrot(t_fractol *f);
void	render_julia(t_fractol *f);
void	print_usage(void);
int		choice_fractal(int ac, char **av, t_fractol *f);
#endif
