/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_clone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:32:55 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/22 14:37:08 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

t_string		*ft_string_clone(const t_string *s)
{
	t_string	*res;

	res = malloc(sizeof(*res));
	*((t_string_cfg *)(&res->cfg)) = s->cfg;
	res->data = ft_memalloc(s->size);
	ft_memcpy(res->data, s->data, s->length);
	res->length = s->length;
	res->size = s->size;
	return (res);
}
