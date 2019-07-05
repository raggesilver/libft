/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:14:17 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 21:29:37 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"
#include "ft_hashtable_priv.h"

void	*ft_hashtable_remove(t_hashtable *self, const char *key)
{
	void	*res;
	size_t	i;

	i = ft_hash(key, self->size);
	if (self->values[i])
	{
		res = self->values[i]->val;
		ft_ht_item_destroy(&self->values[i]);
		self->length--;
		return (res);
	}
	else
		return (NULL);
}
