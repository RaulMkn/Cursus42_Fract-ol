/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:51:03 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/06 18:08:51 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(void *param)
{
	t_fractol	*fractal;

	fractal = (t_fractol *)param;
	if (!fractal)
		return (1);
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(0);
	return (0);
}

static void	data_init(t_fractol *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractol *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_window, fractal);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		close_handler(0, fractal);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, W, H,
			fractal->name);
	if (fractal->mlx_window == NULL)
		close_handler(2, fractal);
	fractal->img.img = mlx_new_image(fractal->mlx_connection, W, H);
	if (fractal->img.img == NULL)
		close_handler(3, fractal);
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits, &fractal->img.line_len, &fractal->img.endlan);
	if (!fractal->img.pixels)
		close_handler(4, fractal);
	events_init(fractal);
	data_init(fractal);
}
