/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 02:00:58 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 02:05:59 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_priv.h"

void	ft_array_insert(t_array *self, size_t index, void *value)
{
	if (index == 0)
		ft_array_prepend(self, value);
	else if (index >= self->length)
		ft_array_push(self, value);
	else
	{
		if (self->length + 1 >= self->size)
			ft_array_grow(self);
		ft_memmove(self->data + index + 1, self->data + index, sizeof(void *) *
			(self->length - index));
		self->length++;
		self->data[index] = value;
		self->data[self->length] = NULL;
	}
}
