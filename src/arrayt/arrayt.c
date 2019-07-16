/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:32:12 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/15 22:32:51 by pqueiroz         ###   ########.fr       */
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
