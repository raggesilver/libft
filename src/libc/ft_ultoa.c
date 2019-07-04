/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:49:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

const char			*g_chars = "0123456789ABCDEF";

char				*ft_ulltoa_base(unsigned long long n, int base)
{
	char				*res;
	int					len;
	int					i;

	len = ft_ull_len_base(n, base);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(len)));
	i = len;
	while (--i >= 0)
	{
		res[i] = g_chars[n % base];
		n /= base;
	}
	return (res);
}

char				*ft_ulltoa(unsigned long long n)
{
	return (ft_ulltoa_base(n, 10));
}

char				*ft_ultoa_base(unsigned long n, int base)
{
	return (ft_ulltoa_base(n, base));
}

char				*ft_ultoa(unsigned long n)
{
	return (ft_ulltoa_base(n, 10));
}
