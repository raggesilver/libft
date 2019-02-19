/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:29:14 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 18:32:46 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *p;

	p = (char *)s;
	while (n > 0)
	{
		if (*p == c)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
