/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:12:38 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 15:21:09 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check_end_not_empty(char const *s, size_t *i)
{
	size_t	lst;

	lst = *i;
	while (*(s + lst))
	{
		if (!ft_iswhitespace(*(s + lst)))
		{
			*i = ++lst;
			return (1);
		}
		++lst;
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		++s;
	i = 0;
	while (*(s + i))
	{
		if (ft_iswhitespace(*(s + i)))
		{
			if (!ft_check_end_not_empty(s, &i))
				break ;
		}
		else
			++i;
	}
	if (!(res = ft_strnew(i)))
		return (NULL);
	res = ft_strncpy(res, s, i);
	return (res);
}
