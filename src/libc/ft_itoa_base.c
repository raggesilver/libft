/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:45:57 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:53:54 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	g_list[16] = "0123456789ABCDEF";

static long	ft_mod(long a)
{
	return ((a < 0) ? -a : a);
}

char		*ft_itoa_base(int val, int base)
{
	char	*res;
	int		i;
	int		len;
	int		ex;

	ex = (val < 0) ? 1 : 0;
	len = ft_int_len_base(val, base);
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = len;
	while (--i >= 0 + ex)
	{
		res[i] = g_list[ft_mod(val % base)];
		val /= base;
	}
	if (ex == 1)
		res[0] = '-';
	return (res);
}
