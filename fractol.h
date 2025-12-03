/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:46:31 by aokur             #+#    #+#             */
/*   Updated: 2025/12/03 15:42:39 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"
# include "mlx.h"

# define WIDTH 400
# define HEIGHT 400
# define MAX_ITER 50

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
	int		color_mode;
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
	int			x;
	int			y;
	double		color;
	double		re;
	double		im;
	t_pixelpmoc	tmp;
}	t_render;

typedef struct s_atod
{
	double	sign;
	double	intp;
	double	frac;
	double	div;
}	t_atod;

void	init_fractol(t_fractol *f);
int		key_handler(int keycode, t_fractol *f);
int		mouse_handler(int button, int x, int y, t_fractol *f);
int		close_window(t_fractol *f);
void	ft_put_pixel(int color, t_fractol *f, t_render a);
void	complexip(double *re, double *im, t_fractol *f, t_render a);
int		color_iter(t_fractol *f, int iter);
void	render_fractol(t_fractol *f);
void	render_mandelbrot(t_fractol *f);
void	render_julia(t_fractol *f);
void	print_usage(void);
int		choice_fractal(int ac, char **av, t_fractol *f);
double	ft_atod(const char *str);
int		color_fire(t_fractol *f, int iter);
int		color_ocean(t_fractol *f, int iter);
int		color_bands(t_fractol *f, int iter);
int		color_default(t_fractol *f, int iter);
#endif
