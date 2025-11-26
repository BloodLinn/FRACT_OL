/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:46:31 by aokur             #+#    #+#             */
/*   Updated: 2025/11/26 06:35:04 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>

#include "libft.h"
#include "mlx.h"

#define WIDTH 1500
#define HEIGHT 1500
#define MAX_ITER 100

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

typedef struct s_mandelbrot
{
	double	zr;
	double	zi;
	double	zr_tmp;
	double	zi_tmp;
}	t_mandelbrot;

void	init_fractol(t_fractol *f);
int		key_handler(int keycode, t_fractol *f);
int		close_window(t_fractol *f);
char	*ft_put_pixel(int x, int y, int color, t_fractol *f);
void	complexip(int x, int y, double *re, double *im, t_fractol *f);
int		mandelbrot_iter(double re, double im);
void	render_mandelbrot(t_fractol *f);

#endif