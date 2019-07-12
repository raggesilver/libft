/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:32:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/12 16:08:55 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	fk_get_words(const char *s, char c)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			res++;
		while (*s && *s != c)
			s++;
	}
	return (res);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**res;
	size_t	i;

	res = malloc(sizeof(*res) * (fk_get_words(s, c) + 1));
	RETURN_VAL_IF_FAIL(NULL, res);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			res[i++] = ft_strdupchr(s, c);
		while (*s && *s != c)
			s++;
	}
	res[i] = NULL;
	return (res);
}
