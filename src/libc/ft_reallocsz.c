/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocsz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:52:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:56:22 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_reallocsz(void *ptr, size_t len, size_t new_len)
{
	void *res;

	if (len == new_len)
		return (ptr);
	if (!new_len)
	{
		if (ptr)
			ft_memdel(&ptr);
		return (NULL);
	}
	if (!(res = malloc(new_len)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(res, ptr, (new_len < len) ? new_len : len);
		ft_memdel(&ptr);
	}
	return (res);
}
