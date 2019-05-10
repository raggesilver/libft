/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_to_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:49:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/09 19:43:49 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long n)
{
	char			*res;
	unsigned long	nn;
	int				len;
	int				i;

	nn = (n < 0) ? -n : n;
	len = ft_ull_len(nn) + (n < 0);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(len)));
	i = len;
	while (--i >= 0 + (n < 0))
	{
		res[i] = '0' + (nn % 10);
		nn /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char	*ft_lltoa(long long n)
{
	char				*res;
	unsigned long long	nn;
	int					len;
	int					i;

	nn = (n < 0) ? -n : n;
	len = ft_ull_len(nn) + (n < 0);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(len)));
	i = len;
	while (--i >= 0 + (n < 0))
	{
		res[i] = '0' + (nn % 10);
		nn /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
