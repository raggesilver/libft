/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:48:21 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 20:41:05 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

void	*ft_hashtable_get(t_hashtable *self, const char *key)
{
	t_ht_item *it;

	it = self->values[ft_hash(key, self->size)];
	return ((it) ? it->val : NULL);
}
