/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:05:06 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/04/19 13:47:33 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

inline void		ft_string_free(t_string *self)
{
	ft_string_destroy(&self);
}

void			ft_string_destroy(t_string **self)
{
	ft_strdel(&(*self)->data);
	free(*self);
	*self = NULL;
}
