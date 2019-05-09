/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:01:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/08 23:44:51 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_array_grow(t_array *self)
{
	self->data = ft_reallocsz(self->data, sizeof(*self->data) * self->size,
		sizeof(*self->data) * (self->size + ARRAY_GROW_SIZE));
	self->size += ARRAY_GROW_SIZE;
}

void		ft_array_push(t_array *self, void *value)
{
	if (self->length + 1 > self->size)
		ft_array_grow(self);
	self->data[self->length++] = value;
}
