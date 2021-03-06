/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:01:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 01:42:39 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_priv.h"

void		ft_array_push(t_array *self, void *value)
{
	if (self->length + 1 >= self->size)
		ft_array_grow(self);
	self->data[self->length++] = value;
	self->data[self->length] = NULL;
}
