/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_inpend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 20:33:31 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/11 20:57:36 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The use of the word inpend must give credit to fprevela
*/

void	ft_string_inpend(t_string *self, size_t index, const char *str)
{
	char	*tmp;
	size_t	len;

	if (index >= self->length)
		ft_string_append(self, str);
	else if (index == 0)
		ft_string_prepend(self, str);
	else
	{
		tmp = self->data;
		len = ft_strlen(str);
		self->data = ft_strnew(self->length + len);
		ft_memcpy(self->data, tmp, index);
		ft_memcpy(self->data + index, str, len);
		ft_strcat(self->data + len + index, tmp + index);
		self->length += len;
		ft_strdel(&tmp);
	}
}
