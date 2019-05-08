/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 23:19:44 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/28 16:26:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	RETURN_VAL_IF_FAIL(NULL, s);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(len)));
	i = 0;
	while (i < len)
		*(res + i++) = *(s + start++);
	return (res);
}
