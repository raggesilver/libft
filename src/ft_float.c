/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:44:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/31 10:28:06 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BIAS			16383
#define MANT_SIZE		63
#define _15BITS			32767

/*
** This function only works with double precision extended floats.
** More on extended precision: https://en.wikipedia.org/wiki/Extended_precision
*/

t_float		ft_float_new(long double n)
{
	t_float res;

	res.sign = (n < 0);
	res.dbl.val = n;
	res.exponent = (*(short *)&res.dbl.bytes[8] & _15BITS) - BIAS - MANT_SIZE;
	res.mantissa = *(uint64_t *)res.dbl.bytes;
	return (res);
}
