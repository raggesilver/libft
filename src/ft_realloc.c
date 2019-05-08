/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:52:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 18:23:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t len)
{
	void *res;

	if (!len)
	{
		if (ptr)
			ft_memdel(&ptr);
		return (NULL);
	}
	if (!(res = malloc(len)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(res, ptr, len);
		ft_memdel(&ptr);
	}
	return (res);
}
