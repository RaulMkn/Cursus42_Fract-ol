/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:08:40 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/02 16:11:49 by rmakende         ###   ########.fr       */
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
		return (mlx_loop(fractal.mlx_connection), 0);
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		fractal.name = argv[1];
		fractal.julia_x = ft_atodbl(argv[2]);
		fractal.julia_y = ft_atodbl(argv[3]);
		fractal_init(&fractal);
		fractal_render(&fractal);
		return (mlx_loop(fractal.mlx_connection), 0);
	}
	else
	{
		ft_putstr_fd("Wrong arguments\nExpected:\n", 1);
		ft_putstr_fd("./fractol mandelbrot\n./fractol julia n1 n2\n", 1);
		ft_putstr_fd("Note: n1 and n2 are expeted to be decimal", 1);
	}
	return (1);
}
