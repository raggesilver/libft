/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:21:11 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 16:21:04 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"
#include "../libft.h"

// static t_ull	fk_upow(t_ull base, size_t expo)
// {
// 	t_ull		res;

// 	if (expo == 0)
// 		return (1);
// 	if (expo == 1 || base == 1)
// 		return (base);
// 	res = base;
// 	while (expo-- > 1)
// 		res *= base;
// 	return (res);
// }

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

	self = malloc(sizeof(*self));
	self->size = HASHTABLE_SIZE;
	self->length = 0;
	self->values = malloc(sizeof(*self->values) * self->size);
	return (self);
}

#define HT_DSTY_ATTR __attribute__((always_inline))
void			ft_hashtable_destroy(t_hashtable **self) HT_DSTY_ATTR;
void			ft_hashtable_destroy(t_hashtable **self)
{
	if ((*self)->values)
		free((*self)->values);
	free(*self);
	*self = NULL;
}

void			ft_hashtable_terminate(t_hashtable **self)
{
	size_t		i;

	i = 0;
	while (i < (*self)->size)
	{
		ft_memdel(&(*self)->values[i]);
		++i;
	}
	ft_hashtable_destroy(self);
}
