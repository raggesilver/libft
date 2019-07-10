/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:19:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/09 17:17:35 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string		*ft_string_new_with_config(const char *s, t_string_cfg cfg)
{
	t_string *self;

	self = malloc(sizeof(*self));
	*((t_string_cfg *)(&self->cfg)) = cfg;
	if (s)
	{
		self->length = ft_strlen(s);
		self->size = self->length + 1 + self->cfg.extra;
		self->data = malloc(self->size);
		ft_memcpy(self->data, s, self->length + 1);
	}
	else
	{
		self->length = 0;
		self->size = STRING_GROW_SIZE + 1;
		self->data = malloc(self->size);
		*self->data = 0;
	}
	return (self);
}

inline t_string	*ft_string_new(const char *s)
{
	return (ft_string_new_with_config(s, g_str_cfg));
}
