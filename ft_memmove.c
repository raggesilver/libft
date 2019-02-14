/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:57:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/13 15:37:08 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	tmp = (unsigned char *)malloc(len);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!tmp)
		return (dst);
	i = 0;
	while (i < len)
	{
		*(tmp + i) = *(s + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(d + i) = *(tmp + i);
		i++;
	}
	free(tmp);
	return (dst);
}
