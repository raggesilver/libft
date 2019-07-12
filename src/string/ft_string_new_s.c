/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:47:51 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/11 18:18:27 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string		*ft_string_new_s(char **s)
{
	t_string *self;

	RETURN_VAL_IF_FAIL(NULL, (s));
	self = ft_string_new(*s);
	ft_strdel(s);
	return (self);
}
