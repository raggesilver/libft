/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:42:18 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/09 00:16:42 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_array_shrink(t_array *self)
{
	self->data = ft_reallocsz(self->data, sizeof(*self->data) * self->size,
		sizeof(*self->data) * (self->size - ARRAY_GROW_SIZE));
	self->size -= ARRAY_GROW_SIZE;
}

static void	ft_array_maybe_shrink(t_array *self)
{
	if (self->length < self->size - ARRAY_GROW_SIZE)
		ft_array_shrink(self);
}

static void	ft_array_shift(t_array *self, size_t start)
{
	while (start + 1 < self->length)
	{
		self->data[start] = self->data[start + 1];
		start++;
	}
}

void		*ft_array_remove(t_array *self, size_t index)
{
	void	*res;

	RETURN_VAL_IF_FAIL(NULL, (index < self->length));
	res = self->data[index];
	self->data[index] = NULL;
	ft_array_shift(self, index);
	self->length--;
	ft_array_maybe_shrink(self);
	return (res);
}

void		ft_array_delete(t_array *self, size_t index)
{
	void	*p;

	RETURN_IF_FAIL((index < self->length));
	p = ft_array_remove(self, index);
	ft_memdel(&p);
}
