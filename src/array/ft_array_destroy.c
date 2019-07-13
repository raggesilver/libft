/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:17:58 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/12 17:29:53 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void	ft_array_destroy(t_array **self)
{
	if ((*self)->data)
		free((*self)->data);
	free(*self);
	*self = NULL;
}

void	ft_array_terminate(t_array **self)
{
	size_t i;

	i = 0;
	while (i < (*self)->length)
		ft_memdel((*self)->data + i++);
	ft_array_destroy(self);
}
