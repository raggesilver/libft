/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:47:51 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 15:23:29 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string		*ft_string_new_s(char **s)
{
	t_string	*self;

	if (!(s && *s))
		return (NULL);
	self = malloc(sizeof(*self));
	*((t_string_cfg *)(&self->cfg)) = g_str_cfg;
	self->length = ft_strlen(*s);
	self->size = self->length;
	self->data = *s;
	*s = NULL;
	return (self);
}
