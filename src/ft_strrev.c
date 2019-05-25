/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 23:51:36 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/23 23:55:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	char	c;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		c = str[i];
		str[i] = str[--len];
		str[len] = c;
		i++;
	}
	return (str);
}
