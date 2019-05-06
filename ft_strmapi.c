/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:39:26 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/28 16:25:50 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	RETURN_VAL_IF_FAIL(NULL, s);
	RETURN_VAL_IF_FAIL(ft_strdup(s), f);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(ft_strlen(s))));
	i = 0;
	while (*(s + i))
	{
		*(res + i) = f(i, *(s + i));
		i++;
	}
	return (res);
}
