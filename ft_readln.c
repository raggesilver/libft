/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readln.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:18:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/06 14:19:58 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	limit_line(const int fd, char **line, char **str)
{
	char	*aux;

	if (ft_strchr(str[fd], '\n'))
	{
		*line = ft_strdupchr(str[fd], '\n');
		aux = ft_strdup(str[fd] + ft_strlen(*line) + 1);
		ft_strdel(&str[fd]);
		if (ft_strlen(aux) > 0)
			str[fd] = aux;
		else
			ft_strdel(&aux);
	}
	else if (str[fd])
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			ft_readln(const int fd, char **line)
{
	static char	*str[4864];
	char		*aux;
	char		ln[BUFF_SIZE + 1];
	int			res;

	if (fd < 0 || fd > 4864 || !line)
		return (-1);
	while ((res = read(fd, ln, BUFF_SIZE)) > 0)
	{
		ln[res] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		aux = ft_strjoin(str[fd], ln);
		ft_strdel(&str[fd]);
		str[fd] = aux;
		if (ft_strchr(ln, '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	if (!res && !str[fd])
		return (0);
	return (limit_line(fd, line, str));
}
