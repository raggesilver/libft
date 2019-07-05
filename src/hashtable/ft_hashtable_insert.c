/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:58:56 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 21:16:50 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_hashtable.h"
#include "ft_hashtable_priv.h"

size_t		ft_hashtable_insert(t_hashtable *self, const char *key, void *value)
{
	t_ht_item	*item;
	size_t		index;

	if (self->length + 1 > self->size)
		ft_hashtable_grow(self);
	item = ft_ht_item_new(key, value);
	index = ft_hash(key, self->size);
	self->values[index] = item;
	self->length++;
	return (index);
}
