/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:44:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/13 17:57:52 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_float		ft_float_new(long double n)
// {
// 	t_float res;

// 	res.sign = (n < 0);
// 	res.un = (t_u_ld_i64){.f = n};
// 	res.exp = res.un.i & (255l << 52);
// 	res.exp = res.exp >> 52;
// 	res.man = res.un.i & ((1l << 52) - 1);
// 	res.den = 1l << 52;
// 	res.num = res.man + res.den;
// 	return (res);
// }

t_float		ft_float_new(long double n)
{
	t_float res;

	res.sign = (n < 0);
	res.un = (t_u_ld_i64){.f = n};

	return (res);
}
