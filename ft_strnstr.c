/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:45:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 19:45:31 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tok;
	char	*ned;
	size_t	l;

	RETURN_VAL_IF_FAIL(((char *)haystack), ft_strcmp(needle, ""));
	ned = (char *)needle;
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			tok = (char *)haystack;
			l = len;
			while (*tok == *ned && *tok && *ned && l > 0)
			{
				tok++;
				ned++;
				l--;
			}
			RETURN_VAL_IF_FAIL(((char *)haystack), *ned);
			ned = (char *)needle;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
