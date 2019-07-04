/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:12:38 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	ft_check_end_not_empty(char const *s, size_t *i)
{
	size_t	lst;

	lst = *i;
	while (*(s + lst))
	{
		if (!ft_isspace(*(s + lst)))
		{
			*i = ++lst;
			return (1);
		}
		lst++;
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*res;

	RETURN_VAL_IF_FAIL(NULL, s);
	while (ft_isspace(*s))
		s++;
	i = 0;
	while (*(s + i))
	{
		if (ft_isspace(*(s + i)))
		{
			if (!ft_check_end_not_empty(s, &i))
			{
				break ;
			}
		}
		else
			i++;
	}
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(i)));
	res = ft_strncpy(res, s, i);
	return (res);
}
