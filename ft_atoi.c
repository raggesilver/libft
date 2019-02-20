/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:47:56 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 23:22:45 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char				*p;
	int					mult;
	unsigned long long	res;

	mult = 0;
	res = 0;
	p = (char *)str;
	while (IS_WHITESPACE(*p))
		p++;
	mult = (*p == '-' && (p++ || 1)) ? -1 : mult;
	mult = ((*p == '+' && !mult && (p++ || 1)) || !mult) ? 1 : mult;
	while (*p >= '0' && *p <= '9' && res <= 9223372036854775807)
		res = (res * 10) + (*p++ - '0');
	if (res > 9223372036854775807)
		return ((mult == -1) ? 0 : -1);
	return (res * mult);
}
