/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_safe_append.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:36:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:39:32 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_safe_append(t_list **head, void *content, size_t size)
{
	if (!head)
		return ;
	if (!*head)
		*head = ft_lstnew(content, size);
	else
		ft_lstappend(*head, content, size);
}
