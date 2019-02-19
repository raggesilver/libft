/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:12:38 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 12:24:11 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*res;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = 0;
	while (*(s + i) && !(*(s + i) == ' ' || *(s + i) == '\n'
		|| *(s + i) == '\t'))
		i++;
	RETURN_X_IF_NOT_Y(NULL, (res = ft_strnew(i + 1)));
	res = ft_strncpy(res, s, i);
	*(res + i) = 0;
	return (res);
}
