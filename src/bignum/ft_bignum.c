/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:24:14 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/24 16:41:40 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bignum		*ft_bignum(const char *str, unsigned base)
{
	t_bignum	*res;

	res = malloc(sizeof(*res));
	res->str = (str) ? str : ft_strdup("0");
	res->length = (str) ? ft_strlen(str) : 1;
	res->base = base;
	return (res);
}

void			ft_bignum_destroy(t_bignum **self)
{
	ft_strdel((char **)&(*self)->str);
	ft_memdel((void **)self);
}
