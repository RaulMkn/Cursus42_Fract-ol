/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:08:40 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/04 15:41:15 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_args(char *argv)
{
	int	i;
	int	flag;
	int	flag2;

	flag = 0;
	flag2 = 0;
	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			if (argv[i] == '.' && flag == 0)
				flag = 1;
			else if ((argv[i] == '-' || argv[i] == '+') && flag2 == 0 && i == 0)
				flag2 = 1;
			else
			{
				ft_putstr_fd("Invalid number. Expected format: ±X.Y\n", 2);
				exit(1);
			}
		}
		i++;
	}
}

static void	handle_julia_args(t_fractol *fractal, char *argv[])
{
	fractal->julia_x = ft_atodbl(argv[2]);
	fractal->julia_y = ft_atodbl(argv[3]);
	handle_args(argv[2]);
	handle_args(argv[3]);
	if (fractal->julia_x > INT_MAX || fractal->julia_y > INT_MAX)
	{
		ft_putstr_fd("Error: Argument out of range.\n", 2);
		exit(1);
	}
	else if (fractal->julia_x < INT_MIN || fractal->julia_y < INT_MIN)
	{
		ft_putstr_fd("Error: Argument out of range.\n", 2);
		exit(1);
	}
}

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
		handle_julia_args(&fractal, argv);
		fractal_init(&fractal);
		fractal_render(&fractal);
		return (mlx_loop(fractal.mlx_connection), 0);
	}
	else
	{
		ft_putstr_fd("Wrong arguments\nExpected:\n", 2);
		ft_putstr_fd("./fractol mandelbrot\n./fractol julia n1 n2\n", 2);
		ft_putstr_fd("Note: n1 and n2 are expected to be decimal.\n", 2);
	}
	return (1);
}
