/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:47:17 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/04 18:14:58 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_handler(int n, t_fractol *fractal)
{
	if (n >= 4)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	if (n >= 3)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (n >= 2)
		mlx_destroy_display(fractal->mlx_connection);
	if (n >= 1)
		free(fractal->mlx_connection);
	exit(1);
}

double	norm(double value, double old_min, double old_max)
{
	return ((value - old_min) / (old_max - old_min));
}

double	map(double norm_value, double new_min, double new_max)
{
	return (new_min + norm_value * (new_max - new_min));
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
