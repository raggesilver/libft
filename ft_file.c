/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:45 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/06 12:59:07 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	*ft_fopen(const char *s, int mode)
{
	t_file *res;

	res = T_FILE(malloc(sizeof(*res)));
	res->fd = open(s, mode);
	res->path = s;
	res->mode = mode;
	return (res);
}

void	ft_fclose(t_file *self)
{
	if (self->fd > -1)
		close(self->fd);
	self->fd = -1;
	self->mode = -1;
}

void	ft_fdestroy(t_file *self)
{
	ft_fclose(self);
	ft_memdel((void **)&self);
}
