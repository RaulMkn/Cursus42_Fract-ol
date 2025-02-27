/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:08:40 by rmakende          #+#    #+#             */
/*   Updated: 2025/02/27 20:14:29 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractal;

	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
		return (0);
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		return (0);
	}
	else
		ft_putstr_fd("Argumentos no validos\n", 1);
}
