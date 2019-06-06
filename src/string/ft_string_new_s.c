/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:47:51 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/05 15:23:41 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_string		*ft_string_new_s(char **str)
{
	t_string *self;

	self = malloc(sizeof(*self));
	self->data = *str;
	self->length = ft_strlen(*str);
	*str = NULL;
	self->append = &ft_string_append;
	self->destroy = &ft_string_destroy;
	return (self);
}
