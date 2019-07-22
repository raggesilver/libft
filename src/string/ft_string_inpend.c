/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_inpend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 20:33:31 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/22 14:41:15 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

/*
** The term "inpend" was brilliantly created by fprevela. For those deprived of
** a decent IQ, inpend is what mere mortals call "insert".
*/

void	ft_string_inpend(t_string *self, size_t index, const char *s)
{
	size_t	len;
	ssize_t	i;

	if (index >= self->length)
		ft_string_append(self, s);
	else if (index == 0)
		ft_string_prepend(self, s);
	else
	{
		len = ft_strlen(s);
		if (self->length + len >= self->size)
			ft_string_grow(self, len);
		i = self->length;
		while (--i >= (ssize_t)index)
			self->data[i + len] = self->data[i];
		i = -1;
		while (++i < (ssize_t)len)
			self->data[index + i] = s[i];
		self->length += len;
		self->data[self->length] = 0;
	}
}
