/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:58:44 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strchrcnt(const char *s, char c)
{
	size_t res;

	res = 0;
	while (*s)
	{
		if (*s == c)
			res++;
		s++;
	}
	return (res);
}
