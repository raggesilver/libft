/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:39:26 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	RETURN_VAL_IF_FAIL(NULL, s);
	RETURN_VAL_IF_FAIL(ft_strdup(s), f);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(ft_strlen(s))));
	i = 0;
	while (*(s + i))
	{
		*(res + i) = f(*(s + i));
		i++;
	}
	return (res);
}
