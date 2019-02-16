/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:24:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/15 17:02:59 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tok;
	char *ned;

	ned = (char *)needle;
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			tok = (char *)haystack;
			while (*tok == *ned && *tok && *ned)
			{
				tok++;
				ned++;
			}
			if (!*ned)
				return ((char *)haystack);
			ned = (char *)needle;
		}
		haystack++;
	}
	return (NULL);
}
