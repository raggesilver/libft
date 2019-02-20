/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:32:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 23:01:07 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*tmp;
	size_t	cnt;
	size_t	tok;
	size_t	i;

	tok = 0;
	cnt = 0;
	i = 0;
	res = NULL;
	while (*s == c)
		s++;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		tok = i;
		while (s[i] && s[i] != c)
			i++;
		if (tok == i)
			continue ;
		RETURN_X_IF_NOT_Y(NULL, (res = ft_realloc(res,
			(cnt + 2) * sizeof(*res))));
		RETURN_X_IF_NOT_Y(NULL, (tmp = ft_strndup(s + tok, i - tok)));
		res[cnt] = tmp;
		res[++cnt] = NULL;
		i++;
	}
	return (res);
}
