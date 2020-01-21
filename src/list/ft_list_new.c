/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:04:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 16:33:28 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_list_new(void *content)
{
	t_list *self;

	self = malloc(sizeof(*self));
	if (!self)
		return (NULL);
	self->content = content;
	self->next = NULL;
	return (self);
}

t_list	*ft_lst_new_s(void **ptr)
{
	t_list *self;

	self = ft_list_new(*ptr);
	*ptr = NULL;
	return (self);
}
