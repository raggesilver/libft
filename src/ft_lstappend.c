/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:04:12 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/01 21:46:30 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *head, void *content, size_t s)
{
	if (!head)
		return ;
	while (head->next)
		head = head->next;
	head->next = ft_lstnew(content, s);
}
