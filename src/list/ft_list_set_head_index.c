/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_set_head_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:22:02 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 18:22:59 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_list_set_head_index(t_list **self, size_t index)
{
	t_list *prev;
	t_list *cur;

	if (!self || !index || index >= ft_list_length(*self))
		return ;
	prev = NULL;
	cur = *self;
	while (index-- > 0 && cur)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return ;
	prev->next = cur->next;
	cur->next = *self;
	*self = cur;
}
