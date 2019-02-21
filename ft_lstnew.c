/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:04:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/20 18:10:09 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *res;

	RETURN_X_IF_NOT_Y(NULL, (res = (t_list *)malloc(sizeof(*res))));
	if (content)
	{
		res->content = ft_memalloc(sizeof(void *));
		ft_memcpy(res->content, content, sizeof(void *));
	}
	res->content_size = (content) ? content_size : 0;
	res->next = NULL;
	return (res);
}
