/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:22:54 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 19:20:59 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void	ft_array_sort(t_array *self, int (*fn)(void *, void *))
{
	size_t	i;
	size_t	j;
	void	*aux;

	i = 0;
	while (i < self->length)
	{
		j = i;
		while (++j < self->length)
			if (fn(self->data[j], self->data[i]) < 0)
			{
				aux = self->data[i];
				self->data[i] = self->data[j];
				self->data[j] = aux;
			}
		i++;
	}
}
