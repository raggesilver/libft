/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:08:26 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/16 17:25:05 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_stdlib.h"

static long	ft_pow(int base, int power)
{
	long	res;

	if (power == 0)
		return (1);
	res = base;
	if(power > 0)
		while (--power > 0)
			res *= base;
	else
		while (++power < 0)
			res /= base;
	return (res);
}

t_string	*ft_ftos(float n, int precision)
{
    long        whole;
    long        decimal;
    char        *tmp;
    t_string    *res;

    whole = (long)(MOD(n));
	if (precision)
	{
		decimal = ((MOD(n)) - whole) * ft_pow(10, precision + 1);
		decimal = (decimal % 10 > 4) ? (decimal / 10 + 1) : (decimal / 10);
		tmp = ft_ltoa(decimal);
		res = ft_string_new_s(&tmp);
		if (precision - ft_int_len(decimal) > 0)
			ft_string_padding(res, 0, precision - ft_int_len(decimal), '0');
		ft_string_prepend(res, ".");
	}
	else
		res = ft_string_new(NULL);
	tmp = ft_ltoa(whole);
	ft_string_prepend_s(res, &tmp);
	if (n < 0)
		ft_string_prepend(res, "-");
    return (res);
}
