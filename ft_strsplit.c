/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:32:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/28 16:33:04 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**res;
	char	*tmp;
	size_t	cnt;

	cnt = 1;
	RETURN_X_IF_NOT_Y(NULL, (s && (res = (char **)malloc(sizeof(*res)))));
	res[0] = NULL;
	while (s && *s)
	{
		tmp = ft_strchr(s, c);
		if (tmp && tmp == s)
		{
			s++;
			continue ;
		}
		RETURN_X_IF_NOT_Y(NULL, (res = ft_realloc(
			res, sizeof(*res) * (cnt + 1))));
		res[cnt - 1] = ft_strdupchr(s, c);
		res[cnt] = NULL;
		if (tmp)
			s += ft_strlen(res[cnt++ - 1]);
		else
			break ;
	}
	return (res);
}
