/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:46:31 by aokur             #+#    #+#             */
/*   Updated: 2025/11/19 17:56:28 by aokur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

#include "libft.h"
#include "mlx.h"

#define WIDTH 800
#define HEIGHT 800

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

void init_fractol(t_fractol *f);
int close_window(t_fractol *f);
int	key_handler(int keycode, t_fractol *f);
void	fill_background(int color, t_fractol *f);

#endif