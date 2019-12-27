/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:20:43 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 15:02:23 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*res;
	size_t	i;

	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
