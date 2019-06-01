/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:08:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/31 15:00:02 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_string	*ft_string_remove(t_string *self, size_t index, size_t len)
{
	char	*tmp;

	RETURN_VAL_IF_FAIL(self, (index < self->length && len > 0));
	if (len + index > self->length)
		len = self->length - index;
	tmp = ft_strnew(self->length - len);
	ft_strncpy(tmp, self->data, index);
	ft_strncpy(tmp + index, self->data + len + index,
		self->length - len - index);
	ft_strdel(&self->data);
	self->data = tmp;
	self->length -= len;
	return (self);
}
