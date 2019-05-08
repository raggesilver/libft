/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:45 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/06 15:48:46 by pqueiroz         ###   ########.fr       */
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

char	*ft_fread(t_file *self)
{
	char	*res;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		r;
	size_t	size;

	size = BUFF_SIZE;
	res = NULL;
	while ((r = read(self->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = 0;
		if (res == NULL || (res && r + ft_strlen(res) > size))
		{
			tmp = res;
			size *= 2;
			res = ft_strnew(size);
			if (tmp)
			{
				ft_strcat(res, tmp);
				ft_strdel(&tmp);
			}
		}
		ft_strcat(res, buf);
	}
	return (res);
}
