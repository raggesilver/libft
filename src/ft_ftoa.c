/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:35:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/13 14:17:26 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static double	ft_pow10(int times)
{
	double res;

	res = 1;
	while (times-- > 0)
		res *= 10;
	return (res);
}

char			*ft_ldtoa(long double n, int precision)
{
	long double	fpart;
	char		*res;
	char		*tmp;
	size_t		len;

	fpart = n - (long double)((long long)n);
	res = ft_lltoa((long long)n);
	if (precision > 0)
	{
		len = ft_strlen(res);
		res = ft_reallocsz(res, len, len + precision + 2);
		res[len + precision + 1] = 0;
		res[len] = '.';
		res[len + 1] = 0;
		tmp = ft_lltoa((long long)(fpart * ft_pow10(MIN(precision, 19))));
		ft_strcat(res, tmp);
		ft_strdel(&tmp);
	}
	return (res);
}
