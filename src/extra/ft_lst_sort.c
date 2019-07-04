/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:22:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_lst_sort(t_list **alst, int (*cmp)(void *, void *))
{
	size_t	i;
	size_t	index;
	t_list	*low;
	t_list	*cur;

	if (!alst || !*alst)
		return ;
	cur = *alst;
	low = cur;
	i = 0;
	index = i;
	while (cur)
	{
		if (cmp(low->content, cur->content) < 0)
		{
			low = cur;
			index = i;
		}
		cur = cur->next;
		++i;
	}
	ft_lst_set_head_index(alst, index);
	ft_lst_sort(&((*alst)->next), cmp);
}
