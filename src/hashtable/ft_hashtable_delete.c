/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_delete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:06:20 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 21:16:28 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"
#include "ft_hashtable_priv.h"

void	ft_hashtable_delete(t_hashtable *self, const char *key)
{
	t_ht_item	*it;
	size_t		i;

	i = ft_hash(key, self->size);
	it = self->values[i];
	if (it)
	{
		ft_ht_item_terminate(&it);
		self->values[i] = NULL;
		self->length--;
	}
}
