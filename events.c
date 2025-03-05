/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:45:00 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/05 13:43:53 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_julia(int key, t_fractol *fractal)
{
	if (key == XK_w)
		fractal->julia_x += 0.25 * fractal->zoom;
	if (key == XK_s)
		fractal->julia_x -= 0.25 * fractal->zoom;
	if (key == XK_a)
		fractal->julia_y += 0.25 * fractal->zoom;
	if (key == XK_d)
		fractal->julia_y -= 0.25 * fractal->zoom;
}

int	key_handler(int key, t_fractol *fractal)
{
	if (key == XK_Escape)
		close_handler(4, fractal);
	else if (key == XK_Left)
		fractal->shift_x -= (1 * fractal->zoom);
	else if (key == XK_Right)
		fractal->shift_x += (1 * fractal->zoom);
	else if (key == XK_Up)
		fractal->shift_y -= (1 * fractal->zoom);
	else if (key == XK_Down)
		fractal->shift_y += (1 * fractal->zoom);
	else if (key == XK_plus || key == XK_KP_Add)
		fractal->iterations = (fractal->iterations * 1.1) + 1;
	else if (key == XK_minus || key == XK_KP_Subtract)
		fractal->iterations /= 1.1;
	if (!ft_strncmp(fractal->name, "julia", 5))
		handle_julia(key, fractal);
	return (fractal_render(fractal), 0);
}

int	mouse_handler(int but, int x, int y, t_fractol *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	if (but == Button5)
		zoom_factor = 1.1;
	else if (but == Button4)
		zoom_factor = 1 / 1.1;
	else
		return (0);
	mouse_re = (x - (W / 2.0)) / (W / 4.0) * fractal->zoom
		+ fractal->shift_x;
	mouse_im = (y - (H / 2.0)) / (H / 4.0) * fractal->zoom
		+ fractal->shift_y;
	fractal->zoom *= zoom_factor;
	fractal->shift_x = mouse_re - (x - (W / 2.0)) / (W / 4.0)
		* fractal->zoom;
	fractal->shift_y = mouse_im - (y - (H / 2.0)) / (H / 4.0)
		* fractal->zoom;
	fractal_render(fractal);
	return (0);
}
