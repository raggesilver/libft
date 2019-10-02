/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:47:56 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/10/01 21:29:43 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
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

int	ft_atoi_base(const char *str, int base)
{
	t_int8		m;
	t_ullong	res;
	char		*digit;

	while (IS_WHITESPACE(*str))
		str++;
	if (*str == '-' && (str++ || 1))
		m = -1;
	else if ((*str == '+' && (str++ || 1)) || 1)
		m = 1;
	res = 0;
	while (*str && (digit = ft_strchr(g_chars, *str)) && g_chars - digit < base
		&& res <= LONG_LONG_MAX)
	{
		res = (res * base) + (digit - g_chars);
		str++;
	}
	if (res > LONG_LONG_MAX)
		return ((m == -1) ? 0 : -1);
	return (res * m);
}
