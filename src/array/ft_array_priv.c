/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_priv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 01:37:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 01:58:36 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void	ft_array_grow(t_array *self)
{
	self->data = ft_reallocsz(self->data, sizeof(*self->data) * self->size,
		sizeof(*self->data) * (self->size + ARRAY_GROW_SIZE));
	self->size += ARRAY_GROW_SIZE;
}

/*
** Move values towards the begining starting at `start`. This function may need
** a better name.
*/

void	ft_array_shift(t_array *self, size_t start)
{
	while (start + 1 < self->length)
	{
		self->data[start] = self->data[start + 1];
		start++;
	}
}

void	ft_array_shrink(t_array *self)
{
	self->data = ft_reallocsz(self->data, sizeof(*self->data) * self->size,
		sizeof(*self->data) * (self->size - ARRAY_GROW_SIZE));
	self->size -= ARRAY_GROW_SIZE;
}

void	ft_array_maybe_shrink(t_array *self)
{
	if (self->length + 1 < self->size - ARRAY_GROW_SIZE)
		ft_array_shrink(self);
}
