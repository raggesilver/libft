/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:10:42 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/14 21:01:36 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;

	p = dest;
	s = src;
	while (n > 0)
	{
		*p = *s;
		if (*s == c)
			return (++p);
		p++;
		s++;
		n--;
	}
	return (NULL);
}
