/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:44:03 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/04 15:51:07 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xE50000
# define GREEN 0x00CC00
# define BLUE 0x0033CC
# define MAGENTA_BURST 0xD100D1
# define LIME_SHOCK 0xBFFF00
# define NEON_ORANGE 0xFF4500
# define PSYCHEDELIC_PURPLE 0x800080
# define AQUA_DREAM 0x00FFFF
# define HOT_PINK 0xFF1493
# define ELECTRIC_BLUE 0x1E90FF
# define LAVA_RED 0xFF2400
# define ULTRA_VIOLET 0x9400D3
# define CYBER_YELLOW 0xFFD700
# define DEEP_TEAL 0x008080
# define RADIANT_TURQUOISE 0x40E0D0
# define BURNING_GOLD 0xFFA500
# define TOXIC_GREEN 0x39FF14
# define MIDNIGHT_BLUE 0x191970
# define SHOCKING_PURPLE 0x9932CC

typedef struct s_image
{
	void	*img;
	void	*pixels;
	int		bits;
	int		endlan;
	int		line_len;
}			t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractol;

void		fractal_init(t_fractol *fractal);
double		map(double norm_value, double new_min, double new_max);
void		fractal_render(t_fractol *fractal);
void		fractal_init(t_fractol *fractal);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
int			key_handler(int keySym, t_fractol *fractal);
int			mouse_handler(int but, int x, int y, t_fractol *fractal);
int			close_handler(int n, t_fractol *fractal);
double		norm(double value, double old_min, double old_max);

#endif