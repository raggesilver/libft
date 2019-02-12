/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:11:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/12 11:17:13 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*p;
	size_t	l;

	l = ft_strlen(s);
	res = (char *)malloc(l + 1);
	p = res;
	while ((*p++ = *s++))
		;
	*p = 0;
	return (res);
}
