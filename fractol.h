/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:44:03 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/01 15:14:22 by rmakende         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000              // RGB(0, 0, 0)
# define WHITE 0xFFFFFF              // RGB(255, 255, 255)
# define RED 0xE50000                // RGB(229, 0, 0)
# define GREEN 0x00CC00              // RGB(0, 204, 0)
# define BLUE 0x0033CC               // RGB(0, 51, 204)
# define MAGENTA_BURST 0xD100D1      // Intense magenta
# define LIME_SHOCK 0xBFFF00         // Neon lime
# define NEON_ORANGE 0xFF4500        // Bright neon orange
# define PSYCHEDELIC_PURPLE 0x800080 // Deep purple
# define AQUA_DREAM 0x00FFFF         // Vibrant cyan
# define HOT_PINK 0xFF1493           // Bright pink
# define ELECTRIC_BLUE 0x1E90FF      // Striking blue
# define LAVA_RED 0xFF2400           // Intense molten red
# define ULTRA_VIOLET 0x9400D3       // Vivid violet
# define CYBER_YELLOW 0xFFD700       // Bright cyber yellow
# define DEEP_TEAL 0x008080          // Dark teal
# define RADIANT_TURQUOISE 0x40E0D0  // Bright turquoise
# define BURNING_GOLD 0xFFA500       // Intense golden orange
# define TOXIC_GREEN 0x39FF14        // Fluorescent green
# define MIDNIGHT_BLUE 0x191970      // Deep blue
# define SHOCKING_PURPLE 0x9932CC    // Eye-catching purple

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
	int		iterations_definition;
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
int			close_handler(t_fractol *fractal);
int			julia_track(int x, int y, t_fractol *fractal);
double		normalize(double value, double old_min, double old_max);

#endif