/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:27:18 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/12 17:29:35 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"


t_array	*ft_array_new(void)
{
	t_array *self;

	self = malloc(sizeof(*self));
	self->data = NULL;
	self->length = 0;
	self->size = 0;
	return (self);
}

/*
** Instantiate a `t_array *` from an array of void pointers and a length `n`. If
** length `n` is -1 the array `values` must be null-terminated.
*/

t_array	*ft_array_new_with_values(void **values, ssize_t n)
{
	t_array *self;

	self = ft_array_new();
	if (n == -1)
	{
		while (values && *values)
			ft_array_push(self, *values++);
	}
	else
	{
		self->size = ((n / ARRAY_GROW_SIZE) + 1) * ARRAY_GROW_SIZE;
		self->data = malloc(sizeof(*self->data) * self->size);
		self->length = n;
		while (--n >= 0)
			self->data[n] = values[n];
		self->data[self->length] = NULL;
	}
	return (self);
}
