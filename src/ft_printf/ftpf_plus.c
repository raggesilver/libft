/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:08:21 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:46:06 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ftpf_plus(t_pinfo *i, t_string *s)
{
	i->fix = 1;
	if (!(s->data[0] != '-'))
		return ;
	if (i->flags & PLUS)
		ft_string_prepend(s, "+");
	else if (i->flags & SPACE)
		ft_string_prepend(s, " ");
	i->fix = (s->data[0] == ' ' || s->data[0] == '+');
}
