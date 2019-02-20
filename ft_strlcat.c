/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:40:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/20 11:54:09 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = ft_strndup(src, size);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (tmp[j])
	{
		dest[j + i] = tmp[j];
		j++;
	}
	return (i + size);
}
