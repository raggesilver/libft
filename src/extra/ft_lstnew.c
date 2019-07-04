/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:04:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *res;

	RETURN_VAL_IF_FAIL(NULL, (res = (t_list *)malloc(sizeof(*res))));
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
