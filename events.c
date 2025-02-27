/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:45:00 by rmakende          #+#    #+#             */
/*   Updated: 2025/02/27 18:33:41 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_handler(t_fractol *fractal)
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
		fractal->shift_x += 1;
	else if (keySym == XK_Right)
		fractal->shift_x -= 1;
	else if (keySym == XK_Up)
		fractal->shift_y -= 1;
	else if (keySym == XK_Down)
		fractal->shift_y += 1;
	else if (keySym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keySym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int but, int x, int y, t_fractol *fractal)
{
	fractal_render(fractal);
	return (0);
}