/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:16:45 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 19:07:58 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void
	fk_list_sort(t_list **self, t_compare_func cmp, int reverse)
{
	size_t	i;
	size_t	index;
	t_list	*low;
	t_list	*cur;

	if (!self || !*self)
		return ;
	reverse = (reverse == FALSE) ? 1 : -1;
	cur = *self;
	low = cur;
	i = 0;
	index = i;
	while (cur)
	{
		if (cmp(low->content, cur->content) * reverse < 0)
		{
			low = cur;
			index = i;
		}
		cur = cur->next;
		++i;
	}
	ft_list_set_head_index(self, index);
	fk_list_sort(&((*self)->next), cmp, (reverse == -1));
}

inline void
	ft_list_sort(t_list **self, t_compare_func cmp)
{
	fk_list_sort(self, cmp, FALSE);
}

inline void
	ft_list_rsort(t_list **self, t_compare_func cmp)
{
	fk_list_sort(self, cmp, TRUE);
}
