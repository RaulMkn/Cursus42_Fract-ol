/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:08:25 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/06 17:13:38 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str, int *flag)
{
	int		i;
	long	sum;
	int		mult;

	i = check_spaces(str);
	sum = 0;
	mult = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		sum = (sum * 10) + (str[i] - '0');
		if ((sum > 2147483647 && mult == 1) || (sum > 2147483648 && mult == -1))
			return (*flag = 1, 0);
		i++;
	}
	return (sum * mult);
}
