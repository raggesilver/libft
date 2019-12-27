/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:04:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:41:06 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *res;

	if (!(res = (t_list *)malloc(sizeof(*res))))
		return (NULL);
	if (content)
	{
		res->content = malloc(content_size);
		ft_memcpy(res->content, content, content_size);
	}
	else
		res->content = NULL;
	res->content_size = (content) ? content_size : 0;
	res->next = NULL;
	return (res);
}
