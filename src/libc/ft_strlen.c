/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:44:41 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/08/20 19:31:54 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	uint32_t	*p;
	char		*ptr;

	p = (uint32_t *)s;
	while (1)
	{
		if (((*p) - 0x01010101UL) & ~(*p) & 0x80808080UL)
		{
			ptr = (char *)p;
			if (ptr[0] == 0)
				return (ptr - s);
			if (ptr[1] == 0)
				return (ptr - s + 1);
			if (ptr[2] == 0)
				return (ptr - s + 2);
			if (ptr[3] == 0)
				return (ptr - s + 3);
		}
		p++;
	}
}
