/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 00:28:36 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/02/01 00:44:22 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strvstr - Find a string str in a string array. If str is empty this
** function will return NULL.
**
** @param {const char **} strv a NULL-terminated string array
** @param {const char *} str the string to look for in strv
** @returns {char *} either a pointer to the found string or NULL
*/

char	*ft_strvstr(const char **strv, const char *str)
{
	if (*str == 0)
		return (NULL);
	while (*strv)
	{
		if (ft_strequ(*strv, str))
			return ((char *)*strv);
		++strv;
	}
	return (NULL);
}
