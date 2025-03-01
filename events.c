/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:45:00 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/01 15:10:40 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(1);
}

int	key_handler(int keySym, t_fractol *fractal)
{
	if (keySym == XK_Escape)
		close_handler(fractal);
	else if (keySym == XK_Left)
		fractal->shift_x += (1 * fractal->zoom);
	else if (keySym == XK_Right)
		fractal->shift_x -= (1 * fractal->zoom);
	else if (keySym == XK_Up)
		fractal->shift_y -= (1 * fractal->zoom);
	else if (keySym == XK_Down)
		fractal->shift_y += (1 * fractal->zoom);
	else if (keySym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keySym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int but, int x, int y, t_fractol *fractal)
{
	x = 0;
	y = 0;
	x = y;
	y = x;
	if (but == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (but == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractol *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(normalize(x, 0, WIDTH), -2, 2)
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(normalize(y, 0, HEIGHT), 2, -2)
				* fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
