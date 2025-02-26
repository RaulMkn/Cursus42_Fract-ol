/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:51:03 by rmakende          #+#    #+#             */
/*   Updated: 2025/02/25 23:15:35 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	
}

void	fractal_init(t_fractol *fractal)
{
	if (((fractal->mlx_connection = mlx_init()) == NULL))
		return ;
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		return ;
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_connection);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		return ;
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits, &fractal->img.line_len, &fractal->img.endlan);
	//events_init(fractal);
	data_init(fractal);
}