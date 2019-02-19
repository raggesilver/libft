/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:11:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 18:34:09 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*p;
	size_t	l;

	l = ft_strlen(s);
	RETURN_X_IF_NOT_Y(NULL, (res = ft_strnew(l + 1)));
	p = res;
	while ((*p++ = *s++))
		;
	return (res);
}
