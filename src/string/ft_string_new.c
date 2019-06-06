/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:19:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/05 15:31:18 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string		*ft_string_new(const char *s)
{
	t_string *self;

	self = malloc(sizeof(*self));
	if (s)
		self->length = ft_strdupsz(&self->data, s);
	else
	{
		self->length = 0;
		self->data = NULL;
	}
	self->append = &ft_string_append;
	self->destroy = &ft_string_destroy;
	return (self);
}
