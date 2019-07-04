/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:20:43 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*res;
	size_t	i;

	RETURN_VAL_IF_FAIL(NULL, (res = ft_memalloc(len + 1)));
	i = 0;
	while (s[i] && i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
