/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:42:32 by rmakende          #+#    #+#             */
/*   Updated: 2025/03/04 23:13:28 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_integer_part(char **s)
{
	long	integer_part;

	integer_part = 0;
	while (**s >= '0' && **s <= '9')
	{
		integer_part = (integer_part * 10) + (**s - '0');
		(*s)++;
	}
	return (integer_part);
}

double	ft_atoi_fractional_part(char **s)
{
	double	fractional_part;
	double	divisor;

	fractional_part = 0.0;
	divisor = 1.0;
	if (**s == '.')
		(*s)++;
	while (**s >= '0' && **s <= '9')
	{
		divisor *= 10;
		fractional_part += (**s - '0') / divisor;
		(*s)++;
	}
	return (fractional_part);
}

double	ft_atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	int		sign;

	integer_part = 0;
	fractional_part = 0.0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '.')
		return (0);
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (*s == '.' || (*s >= '0' && *s <= '9'))
		integer_part = ft_atoi_integer_part(&s);
	if (*s == '.')
		fractional_part = ft_atoi_fractional_part(&s);
	return (sign * (integer_part + fractional_part));
}
