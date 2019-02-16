/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:39:26 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/15 22:54:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	RETURN_X_IF_NOT_Y(NULL, s);
	RETURN_X_IF_NOT_Y(ft_strdup(s), f);
	RETURN_X_IF_NOT_Y(NULL, (res = ft_strnew(ft_strlen(s) + 1)));
	i = 0;
	while (*(s + i))
	{
		*(res + i) = f(i, *(s + i));
		i++;
	}
	return (res);
}
