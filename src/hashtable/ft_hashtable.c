/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:21:11 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 19:58:27 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_hashtable.h"
#include "ft_hashtable_priv.h"

/*
** sdbm hashing function. Adapted from:
** http://www.cse.yorku.ca/~oz/hash.html - 2019/07/04 17:46:20 GMT-0700
*/

size_t			ft_hash(const char *key, const size_t size)
{
	size_t		hash;

	hash = 0;
	while (*key)
		hash = (int)(*key++) + (hash << 6) + (hash << 16) - hash;
	return (hash % size);
}

t_hashtable		*ft_hashtable_new()
{
	t_hashtable	*self;
	size_t		i;

	self = malloc(sizeof(*self));
	self->size = HASHTABLE_SIZE;
	self->length = 0;
	self->values = malloc(sizeof(*self->values) * self->size);
	i = 0;
	while (i < self->size)
		self->values[i++] = NULL;
	return (self);
}

void			ft_hashtable_destroy(t_hashtable **self)
{
	size_t i;

	i = 0;
	while (i < (*self)->size)
	{
		if ((*self)->values[i])
			ft_ht_item_destroy(&(*self)->values[i]);
		++i;
	}
	ft_memdel((void **)self);
}

void			ft_hashtable_terminate(t_hashtable **self)
{
	size_t i;

	i = 0;
	while (i < (*self)->size)
	{
		if ((*self)->values[i])
			ft_ht_item_terminate(&(*self)->values[i]);
		++i;
	}
	ft_memdel((void **)self);
}
