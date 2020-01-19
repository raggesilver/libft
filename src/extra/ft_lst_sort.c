/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:22:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/19 14:41:36 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_lst_sort_full(t_list **alst, t_compare_func cmp, int reverse)
{
		size_t	i;
		size_t	index;
		t_list	*low;
		t_list	*cur;

		if (!alst || !*alst)
			return ;
		reverse = (reverse == FALSE) ? 1 : -1;
		cur = *alst;
		low = cur;
		i = 0;
		index = i;
		while (cur)
		{
			if ((cmp(low->content, cur->content) * reverse) < 0)
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

void		ft_lst_sort(t_list **alst, int (*cmp)(void *, void *))
{
	ft_lst_sort_full(alst, cmp, FALSE);
}
