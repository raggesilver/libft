/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:18:36 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 17:20:05 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_list_length(t_list *self)
{
	size_t	res;

	res = 0;
	while (self)
	{
		res++;
		self = self->next;
	}
	return (res);
}
