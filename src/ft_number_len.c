/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:33:51 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/09 18:29:10 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_int_len(int n)
{
	return (ft_int_len_base(n, 10));
}

size_t		ft_ull_len(unsigned long long n)
{
	size_t				res;

	res = 1;
	while ((n /= 10))
		res++;
	return (res);
}
