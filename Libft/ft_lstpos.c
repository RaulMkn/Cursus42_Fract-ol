/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:29:57 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/27 18:35:12 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpos(t_list *head, int position)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->index == position)
			return (i);
		head = head->next;
		i++;
	}
	return (i);
}
