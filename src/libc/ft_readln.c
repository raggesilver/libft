/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readln.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:18:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	fk_limit_line(const int fd, char **line, char **ss, char *nln)
{
	char	*aux;
	size_t	len;

	if (nln)
	{
		*line = ft_strdupchr(ss[fd], '\n');
		len = ft_strlen(*line);
		if (*(ss[fd] + len) && *(ss[fd] + len + 1))
		{
			aux = ft_strdup(ss[fd] + len + 1);
			ft_strdel(&ss[fd]);
			ss[fd] = aux;
		}
		else
			ft_strdel(&ss[fd]);
	}
	else
	{
		*line = ft_strdup(ss[fd]);
		ft_strdel(&ss[fd]);
	}
	return (1);
}

int			ft_readln(const int fd, char **line)
{
	static char *ss[4864];
	char		*aux;
	char		buff[BUFF_SIZE + 1];
	int			red;

	if (fd < 0 || fd > 4864 || !line)
		return (-1);
	aux = NULL;
	while ((red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = 0;
		aux = ft_strjoin(ss[fd], buff);
		ft_strdel(&ss[fd]);
		ss[fd] = aux;
		if ((aux = ft_strchr(buff, '\n')))
			break ;
	}
	if (red < 0)
		return (-1);
	if (red == 0 && !ss[fd])
		return (0);
	return (fk_limit_line(fd, line, ss, aux));
}
