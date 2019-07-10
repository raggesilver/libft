/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:47:51 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/09 19:39:33 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string		*ft_string_new_s(char **s)
{
	t_string *self;

	self = ft_string_new(*s);
	ft_strdel(s);
	return (self);
}
