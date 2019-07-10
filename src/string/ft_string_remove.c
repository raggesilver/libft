/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:08:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/10 01:10:46 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_string	*ft_string_remove(t_string *self, size_t index, size_t len)
{
	ssize_t	i;

	RETURN_VAL_IF_FAIL(self, (index < self->length && len > 0));
	if (len + index > self->length)
	{
		self->data[index] = 0;
		self->length = index;
		return (self);
	}
	i = index + len - 1;
	while (++i < (ssize_t)self->length)
		self->data[i - len] = self->data[i];
	self->data[i - len] = 0;
	self->length -= len;
	self->data[self->length] = 0;
	return (self);
}
