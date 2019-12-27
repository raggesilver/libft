/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:42:18 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 02:07:11 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_priv.h"

void		*ft_array_remove(t_array *self, size_t index)
{
	void	*res;

	if (index >= self->length)
		return (NULL);
	res = self->data[index];
	self->data[index] = NULL;
	ft_array_shift(self, index);
	self->length--;
	ft_array_maybe_shrink(self);
	self->data[self->length] = NULL;
	return (res);
}

void		ft_array_delete(t_array *self, size_t index)
{
	void	*p;

	if (index >= self->length)
		return ;
	p = ft_array_remove(self, index);
	ft_memdel(&p);
}
