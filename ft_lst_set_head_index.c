/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_set_head_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:22:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/04/24 14:36:21 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_set_head_index(t_list **alst, size_t index)
{
	t_list *prev;
	t_list *cur;

	if (!alst || !index || index >= ft_lstcnt(*alst))
		return ;
	prev = NULL;
	cur = *alst;
	while (index-- > 0 && cur)
	{
		prev = cur;
		cur = cur->next;
	}
	RETURN_IF_NOT(cur);
	prev->next = cur->next;
	cur->next = *alst;
	*alst = cur;
}
