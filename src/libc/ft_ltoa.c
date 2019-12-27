/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:49:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:54:44 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char				*ft_lltoa_base(long long n, int base)
{
	char				*res;
	unsigned long long	nn;
	int					len;
	int					i;

	nn = (n < 0) ? -n : n;
	len = ft_ull_len(nn) + (n < 0);
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = len;
	while (--i >= 0 + (n < 0))
	{
		res[i] = g_chars[nn % base];
		nn /= base;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char				*ft_lltoa(long long n)
{
	return (ft_lltoa_base(n, 10));
}

char				*ft_ltoa_base(long n, int base)
{
	return (ft_lltoa_base(n, base));
}

char				*ft_ltoa(long n)
{
	return (ft_ltoa_base(n, 10));
}
