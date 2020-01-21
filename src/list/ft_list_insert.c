/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:35:57 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 17:57:43 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** This file contains functions related to inserting elements into a t_list.
*/

/*
** ft_list_append add an item to the end of a list. If the list is not
** initialized yet (does not have a head), the new element will be set as head.
**
** @param {t_list **} self a pointer to the list head (may POINT to NULL)
** @param {void *} content the element
*/

void	ft_list_append(t_list **self, void *content)
{
	if (!(*self))
		*self = ft_list_new(content);
	else
		ft_list_get_last(*self)->next = ft_list_new(content);
}

void	ft_list_prepend(t_list **self, void *content)
{
	t_list *it;

	if (!(*self))
		*self = ft_list_new(content);
	else
	{
		it = ft_list_new(content);
		it->next = *self;
		*self = it;
	}
}

void	ft_list_insert(t_list **self, void *content, size_t index)
{
	size_t	len;
	t_list	*it;
	t_list	*el;

	if (!(*self))
		*self = ft_list_new(content);
	else
	{
		len = ft_list_length(*self);
		if (index >= len - 1)
			ft_list_append(self, content);
		else if (index == 0)
			ft_list_prepend(self, content);
		else
		{
			it = ft_list_get_index(*self, index - 1);
			el = ft_list_new(content);
			el->next = it->next;
			it->next = el;
		}
	}
}
