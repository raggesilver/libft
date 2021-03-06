/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:15:23 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:57:32 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Returns a copy of (char *)str up to (char c). If c isn't found a copy of
** (char *str) is returned. Any allocation failure will return NULL
*/

char	*ft_strdupchr(const char *str, char c)
{
	char *res;
	char *tmp;

	if (!str)
		return (NULL);
	if (!(tmp = ft_strchr(str, c)))
		return (ft_strdup(str));
	res = ft_strndup(str, tmp - str);
	return (res);
}
