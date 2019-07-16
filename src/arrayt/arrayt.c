/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:32:12 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/16 00:13:48 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayt.h"

void	arrayt_grow(void **data, size_t dsize, size_t *size)
{
	if (*size == 0)
		*data = ft_memalloc(10 * dsize);
	else
		*data = ft_reallocsz(*data, (*size) * dsize, ((*size) + 10) * dsize);
	*size += 10;
}

void	arrayt_destroy(void **self, void **data)
{
	ft_memdel(data);
	ft_memdel(self);
}

void	arrayt_remove(char *data, size_t dsize, size_t *len, size_t i)
{
	if (i >= *len)
		return ;
	if (i + 1 < *len)
		ft_memmove((void *)(data + (i * dsize)), data + (dsize * (i + 1)),
			dsize * (*len - i - 1));
	else
		ft_memset((void *)(data + (i * dsize)), 0, dsize);
	(*len)--;
}

void	arrayt_make_room(char *data, size_t dsize, size_t *len, size_t i)
{
	if (i >= *len)
		return ;
	ft_memmove((void *)(data + (i * dsize)), data + (dsize * (i + 1)),
		dsize * (*len - i - 1));
}
