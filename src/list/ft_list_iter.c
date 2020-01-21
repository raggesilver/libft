/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:20:32 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 17:35:29 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** This file contains functions based on iteratin through t_list's elements.
*/

/*
** ft_list_map generate a new t_list from the returned value of a function
** executed for each element in the original list.
*/

t_list	*ft_list_map(t_list *self, t_map_func fn)
{
	t_list *res;
	t_list *it;

	if (self == NULL || fn == NULL)
		return (NULL);
	res = ft_list_new(fn(self->content));
	it = res;
	while ((self = self->next))
	{
		it->next = ft_list_new(fn(self->content));
		it = it->next;
	}
	return (res);
}

void	ft_list_foreach(t_list *self, t_foreach_func fn)
{
	while (self)
	{
		fn(self->content);
		self = self->next;
	}
}
