/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:47:56 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/15 00:08:28 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(const char *str)
{
	char		*p;
	t_int8		mult;
	t_ullong	res;

	mult = 0;
	res = 0;
	p = (char *)str;
	while (IS_WHITESPACE(*p))
		p++;
	if (*p == '-' && (p++ || 1))
		mult = -1;
	else if ((*p == '+' && (p++ || 1)) || 1)
		mult = 1;
	while (*p >= '0' && *p <= '9' && res <= LONG_LONG_MAX)
		res = (res * 10) + (*p++ - '0');
	if (res > LONG_LONG_MAX)
		return ((mult == -1) ? 0 : -1);
	return (res * mult);
}
