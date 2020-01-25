/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:24:14 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 20:56:53 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bignum.h"

t_bignum		*ft_bignum_new(const char *str)
{
	t_bignum	*res;
	char		*aux;

	res = malloc(sizeof(*res));
	res->str = ft_string_new(str ? str : "0");
	if (str && (aux = ft_strchr(res->str->data, '.')))
		res->point = aux - res->str->data;
	else
		res->point = -1;
	return (res);
}

t_bignum		*ft_bignum_new_s(const char *str)
{
	t_bignum	*res;
	char		*tmp;

	res = malloc(sizeof(*res));
	tmp = (char *)str;
	res->str = ft_string_new_s(&tmp);
	if ((tmp = ft_strchr(res->str->data, '.')))
		res->point = tmp - res->str->data;
	else
		res->point = -1;
	return (res);
}

void			ft_bignum_destroy(t_bignum **self)
{
	ft_string_destroy(&(*self)->str);
	ft_memdel((void **)self);
}
