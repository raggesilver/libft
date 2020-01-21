/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:44:25 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 18:57:55 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** This file contains functions related to getting items from a t_list.
*/

t_list	*ft_list_get_index(t_list *self, size_t index)
{
	while (self)
	{
		if (index == 0)
			return (self);
		self = self->next;
		--index;
	}
	return (NULL);
}

t_list	*ft_list_get_last(t_list *self)
{
	if (!self)
		return (NULL);
	while (self->next)
		self = self->next;
	return (self);
}

void	*ft_list_get_item(t_list *self, size_t index)
{
	while (self)
	{
		if (index == 0)
			return (self->content);
		self = self->next;
		--index;
	}
	return (NULL);
}

void	*ft_list_get_last_item(t_list *self)
{
	if (!self)
		return (NULL);
	while (self->next)
		self = self->next;
	return (self->content);
}
