/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:47:51 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/22 16:21:53 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string		*ft_string_new_s(char **s)
{
	t_string	*self;

	RETURN_VAL_IF_FAIL(NULL, (s && *s));
	self = malloc(sizeof(*self));
	*((t_string_cfg *)(&self->cfg)) = g_str_cfg;
	self->length = ft_strlen(*s);
	self->size = self->length;
	self->data = *s;
	*s = NULL;
	return (self);
}
