/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_prepend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 01:28:21 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 01:55:11 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_priv.h"

void	ft_array_prepend(t_array *self, void *value)
{
	if (self->length + 1 >= self->size)
		ft_array_grow(self);
	ft_memmove(self->data + 1, self->data, sizeof(void *) * self->length);
	self->data[0] = value;
	self->length++;
	self->data[self->length] = NULL;
}
