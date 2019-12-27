/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:45:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 15:17:35 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos;
	size_t	i;

	if (*needle == 0)
		return ((char *)haystack);
	pos = 0;
	while (haystack[pos] && pos < len)
	{
		if (haystack[pos] == *needle)
		{
			i = 1;
			while (haystack[pos + i] && haystack[pos + i] == needle[i]
				&& (pos + i) < len)
				++i;
			if (needle[i] == 0)
				return ((char *)(haystack + pos));
		}
		++pos;
	}
	return (NULL);
}
