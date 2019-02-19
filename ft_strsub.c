/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 23:19:44 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 19:08:27 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	RETURN_X_IF_NOT_Y(NULL, (res = ft_strnew(len + 1)));
	i = 0;
	while (i < len)
		*(res + i++) = *(s + start++);
	return (res);
}
