/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:18:51 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/04 18:52:29 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits / 8));
	*(unsigned int *)(img->pixels + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.x = (map(norm(x, 0, WIDTH), -2, 2) * fractal->zoom) + fractal->shift_x;
	z.y = (map(norm(y, 0, HEIGHT), 2, -2) * fractal->zoom) + fractal->shift_y;
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c.x = fractal->julia_x;
		c.y = fractal->julia_y;
	}
	else
		c = z;
	while (++i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if (sqrt(pow(z.x, 2) + pow(z.y, 2)) > fractal->escape_value)
		{
			return (color = map(norm(i, 0, fractal->iterations), WHITE,
					ULTRA_VIOLET), my_pixel_put(x, y, &fractal->img, color));
		}
	}
	my_pixel_put(x, y, &fractal->img, BURNING_GOLD);
}

void	fractal_render(t_fractol *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img, 0, 0);
}
