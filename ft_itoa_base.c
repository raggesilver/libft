/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:45:57 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/18 17:13:47 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(int n, int base)
{
	char	*res;
	char	*hex_digits;
	int		len;
	int		ex;
	long	val;

	hex_digits = ft_strdup("0123456789ABCDEF");
	len = ft_int_len_base(n, base);
	ex = (n < 0) ? 1 : 0;
	val = (ex) ? -n : n;
	res = ft_strnew(len + 1);
	while (--len >= ex)
	{
		res[len] = hex_digits[val % base];
		val /= base;
	}
	if (ex == 1)
		res[0] = '-';
	return (res);
}
