/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_priv_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:59:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 15:25:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

const t_string_cfg		g_str_cfg = {
	.extra=20,
	.growmode=T_STRING_GROWMODE_FIXED
};

/*
** Helper function that dups a string and returns it's size without calling
** ft_strlen twice
*/

size_t					ft_strdupsz(char **dest, const char *s)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s);
	*dest = malloc(sizeof(**dest) * (len + 1));
	p = *dest;
	while ((*p++ = *s++))
		;
	return (len);
}

static inline size_t	fk_get_high_bit(size_t num)
{
	size_t	res;

	if (num == 0)
		return (0);
	res = 1;
	while (num >>= 1)
		res <<= 1;
	return (res);
}

inline size_t			ft_string_min_size(size_t mode, size_t size,
											size_t min_len)
{
	size_t	res;

	if (mode == T_STRING_GROWMODE_DOUBLE)
	{
		res = size;
		while (res < min_len)
			res *= 2;
	}
	else if (mode == T_STRING_GROWMODE_QUADRATIC)
	{
		res = fk_get_high_bit(min_len);
		res <<= 1;
	}
	else
	{
		res = ((int)(min_len / STRING_GROW_SIZE) + 1) * STRING_GROW_SIZE;
	}
	return (res);
}

/*
** This function grows the allocated space for the t_string. If add_len > 0 this
** function will guarantee the final size is enough to fit current len + add_len
** while still respecting the string grow mode
*/

void					ft_string_grow(t_string *self, size_t add_len)
{
	char *tmp;

	if (add_len > 0)
	{
		self->size = ft_string_min_size(
			self->cfg.growmode, self->size, self->length + add_len);
	}
	else
	{
		if (self->cfg.extra == T_STRING_GROWMODE_DOUBLE)
			self->size *= 2;
		else if (self->cfg.extra == T_STRING_GROWMODE_QUADRATIC)
		{
			self->size = fk_get_high_bit(self->size);
			self->size <<= 1;
		}
		else
			self->size += STRING_GROW_SIZE;
	}
	tmp = ft_memalloc(self->size);
	ft_memcpy(tmp, self->data, self->length + 1);
	ft_strdel(&self->data);
	self->data = tmp;
}
