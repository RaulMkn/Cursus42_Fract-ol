/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:51:03 by rmakende          #+#    #+#             */
/*   Updated: 2025/02/26 16:16:21 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
}

void	fractal_cleanup(t_fractol *fractal)
{
	if (fractal->img.img)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	if (fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		return ;
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		fractal_cleanup(fractal);
		return ;
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		fractal_cleanup(fractal);
		return ;
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits, &fractal->img.line_len, &fractal->img.endlan);
	if (fractal->img.pixels == NULL)
	{
		fractal_cleanup(fractal);
		return ;
	}
	data_init(fractal);
	// events_init(fractal);
}
