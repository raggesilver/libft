/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:25:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:40:43 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *res_last;

	if (!lst)
		return (NULL);
	res = NULL;
	res_last = res;
	while (lst)
	{
		if (res)
		{
			res_last->next = f(lst);
			res_last = res_last->next;
		}
		else
		{
			res = f(lst);
			res_last = res;
		}
		lst = lst->next;
	}
	return (res);
}
