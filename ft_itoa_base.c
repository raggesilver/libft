/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:45:57 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 20:50:50 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	g_list[16] = "0123456789ABCDEF";

long	ft_mod(long a)
{
	return ((a < 0) ? -a : a);
}

char	*ft_itoa_base(int val, int base)
{
	char	*res;
	int		i;
	int		len;
	int		ex;
	long	value;

	ex = (val < 0) ? 1 : 0;
	value = ft_mod((long)val);
	len = ft_int_len_base(value, base);
	RETURN_X_IF_NOT_Y(NULL, (res = ft_strnew(len + 1 + ex)));
	i = len + ex;
	while (--i >= 0 + ex)
	{
		res[i] = g_list[value % base];
		value /= base;
	}
	if (ex == 1)
		res[0] = '-';
	return (res);
}
