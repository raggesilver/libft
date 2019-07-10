/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 23:02:23 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/09 17:45:23 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_string_to_lower(t_string *self)
{
	size_t	i;

	i = 0;
	while (i < self->length)
	{
		self->data[i] = ft_tolower(self->data[i]);
		i++;
	}
}

void		ft_string_to_upper(t_string *self)
{
	size_t	i;

	i = 0;
	while (i < self->length)
	{
		self->data[i] = ft_toupper(self->data[i]);
		i++;
	}
}
