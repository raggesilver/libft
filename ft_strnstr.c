/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:45:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/14 14:52:20 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char *tok;
	char *ned;

	ned = (char *)needle;
	while (*haystack && len > 0) {
		if (*haystack == *needle) {
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
		len--;
	}
	return (NULL);
}
