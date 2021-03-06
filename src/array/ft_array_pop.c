/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:23:05 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/12 17:27:33 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** Remove and return the last element from the array. Does not free.
*/

void	*ft_array_pop(t_array *self)
{
	if (self->length == 0)
		return (NULL);
	else
		return (ft_array_remove(self, self->length - 1));
}
