/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:47:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/08/24 18:50:39 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string	*ft_string_new_n(const char *s, size_t size)
{
	t_string *self;

	self = malloc(sizeof(*self));
	*((t_string_cfg *)(&self->cfg)) = g_str_cfg;
	self->data = ft_strnew(size);
	self->length = size;
	self->size = size;
	ft_memcpy(self->data, s, size);
	self->data[size] = 0;
	return (self);
}
