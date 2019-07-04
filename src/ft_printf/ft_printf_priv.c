/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_priv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:07:01 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/26 13:07:21 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

void		blah(t_pinfo *i, int *p, int n)
{
	if (n < 0)
	{
		i->flags |= MINUS;
		i->flags &= ~ZERO;
		if (n == INT_MIN)
			n = INT_MAX;
		else
			n = -n;
	}
	*p = n;
}
