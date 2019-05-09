/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:45 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/09 00:16:59 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_file		*ft_fopen(const char *s, int mode)
{
	t_file *res;

	res = T_FILE(malloc(sizeof(*res)));
	res->fd = open(s, mode);
	res->path = s;
	res->mode = mode;
	return (res);
}

void		ft_fdestroy(t_file *self)
{
	ft_fclose(self);
	ft_memdel((void **)&self);
}

void		ft_fclose(t_file *self)
{
	if (self->fd > -1)
		close(self->fd);
	self->fd = -1;
	self->mode = -1;
}

t_string	*ft_fread(t_file *self)
{
	t_string	*res;
	char		buf[BUFF_SIZE + 1];
	int			r;

	RETURN_VAL_IF_FAIL(NULL, ((self->mode & O_RDONLY) == O_RDONLY ||
		(self->mode & O_RDWR) == O_RDWR));
	res = ft_string_new("");
	while ((r = read(self->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = 0;
		ft_string_append(res, buf);
	}
	return (res);
}

int			ft_fwrite(t_file *self, t_string *s)
{
	RETURN_VAL_IF_FAIL(-1, ((self->mode & O_WRONLY) == O_WRONLY ||
		(self->mode & O_RDWR) == O_RDWR));
	return (write(self->fd, s->data, s->length));
}
