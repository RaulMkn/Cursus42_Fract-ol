/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:45:00 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/02 16:12:47 by rmakende         ###   ########.fr       */
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

static void	handle_julia(int key, t_fractol *fractal)
{
	if (key == XK_w)
		fractal->julia_y -= DELTA * fractal->zoom;
	if (key == XK_s)
		fractal->julia_y += DELTA * fractal->zoom;
	if (key == XK_a)
		fractal->julia_x -= DELTA * fractal->zoom;
	if (key == XK_d)
		fractal->julia_x += DELTA * fractal->zoom;
}

int	key_handler(int key, t_fractol *fractal)
{
	if (key == XK_Escape)
		close_handler(fractal);
	else if (key == XK_Left)
		fractal->shift_x += (1 * fractal->zoom);
	else if (key == XK_Right)
		fractal->shift_x -= (1 * fractal->zoom);
	else if (key == XK_Up)
		fractal->shift_y -= (1 * fractal->zoom);
	else if (key == XK_Down)
		fractal->shift_y += (1 * fractal->zoom);
	else if (key == XK_plus || key == XK_KP_Add)
		fractal->iterations_definition *= 1.1;
	else if (key == XK_minus || key == XK_KP_Subtract)
		fractal->iterations_definition /= 1.1;
	if (!ft_strncmp(fractal->name, "julia", 5))
		handle_julia(key, fractal);
	return (fractal_render(fractal), 0);
}

int	mouse_handler(int but, int x, int y, t_fractol *fractal)
{
	x = 0;
	y = 0;
	x = y;
	y = x;
	if (but == Button4)
		fractal->zoom /= 1.1;
	else if (but == Button5)
		fractal->zoom *= 1.1;
	fractal_render(fractal);
	return (0);
}
