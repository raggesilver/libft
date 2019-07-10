/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_priv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:58:45 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/10 01:22:49 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"
#include "ft_hashtable_priv.h"

t_ht_item		*ft_ht_item_new(const char *key, void *val)
{
	t_ht_item	*self;

	self = malloc(sizeof(*self));
	self->key = ft_strdup(key);
	self->val = val;
	return (self);
}

void			ft_ht_item_destroy(t_ht_item **self)
{
	ft_strdel(&(*self)->key);
	ft_memdel((void **)self);
}

void			ft_ht_item_terminate(t_ht_item **self)
{
	ft_strdel(&(*self)->key);
	ft_memdel((void **)&(*self)->val);
	ft_memdel((void **)self);
}

void			ft_hashtable_grow(t_hashtable *self)
{
	t_ht_item	**values;
	ssize_t		i;
	ssize_t		old_size;

	old_size = self->size;
	if (HASHTABLE_DOUBLE)
		self->size *= 2;
	else
		self->size += HASHTABLE_SIZE;
	values = malloc(sizeof(*values) * self->size);
	i = self->size;
	while (--i >= 0)
		values[i] = NULL;
	i = old_size;
	while (--i >= 0)
		if (self->values[i])
			values[ft_hash(self->values[i]->key, self->size)] = self->values[i];
	ft_memdel((void **)&(self->values));
	self->values = values;
}
