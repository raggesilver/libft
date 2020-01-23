/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:03:30 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/22 15:11:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** This file contains functions related to removing items from a t_list.
*/

/*
** ft_list_remove free the list item and return the content.
*/

void	*ft_list_remove(t_list **self, size_t index)
{
	t_list	*prev;
	t_list	*cur;
	void	*res;

	prev = NULL;
	cur = *self;
	while (cur)
	{
		if (index == 0)
		{
			res = cur->content;
			if (prev)
				prev->next = cur->next;
			else
				*self = cur->next;
			free(cur);
			return (res);
		}
		prev = cur;
		cur = cur->next;
		--index;
	}
	return (NULL);
}

/*
** ft_list_delete free both the list item and the content.
*/

void	ft_list_delete(t_list **self, size_t index)
{
	ft_list_delete_with_func(self, index, &free);
}

/*
** ft_list_delete_with_func free the list item and destroy the content using a
** function.
*/

void	ft_list_delete_with_func(t_list **self, size_t index, t_destroy_func fn)
{
	void *content;

	content = ft_list_remove(self, index);
	if (content)
		fn(content);
}
