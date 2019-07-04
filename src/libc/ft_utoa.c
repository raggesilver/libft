/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:49:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char				*ft_utoa_base(unsigned n, int base)
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

char				*ft_utoa(unsigned n)
{
	return (ft_utoa_base(n, 10));
}
