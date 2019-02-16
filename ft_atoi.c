/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:47:56 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/15 08:28:11 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*p;
	int		mult;
	int		res;

	mult = 0;
	res = 0;
	p = (char *)str;
	while (IS_WHITESPACE(*p))
		p++;
	mult = (*p == '-' && (p++ || 1)) ? -1 : mult;
	mult = ((*p == '+' && (p++ || 1)) || !mult) ? 1 : mult;
	while (*p >= '0' && *p <= '9')
		res = (res * 10) + (*p++ - '0');
	return (res * mult);
}
