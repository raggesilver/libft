/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:16:53 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/22 16:01:03 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_list_destroy(t_list **self)
{
	ft_list_destroy_with_func(self, NULL);
}

void	ft_list_destroy_with_func(t_list **self, t_destroy_func fn)
{
	t_list *it;
	t_list *next;

	it = *self;
	while (it)
	{
		if (it->content && fn)
			fn(it->content);
		next = it->next;
		free(it);
		it = next;
	}
	*self = NULL;
}

void	ft_list_terminate(t_list **self)
{
	ft_list_destroy_with_func(self, &free);
}
