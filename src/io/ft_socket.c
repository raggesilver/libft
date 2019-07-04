/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:05:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 21:48:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_socket			*ft_socket_new_with_port(int port)
{
	t_socket		*res;

	res = malloc(sizeof(*res));
	res->fd = socket(AF_INET, SOCK_STREAM, 0);
	ft_bzero(&res->address, sizeof(res->address));
	res->address.sin_addr.s_addr = INADDR_ANY;
	res->address.sin_port = htons((port > 0) ? port : 80);
	res->address.sin_family = AF_INET;
	return (res);
}

t_socket			*ft_socket_new(void)
{
	return (ft_socket_new_with_port(-1));
}

int					ft_socket_bind(t_socket *self)
{
	int res;

	res = bind(self->fd, (const struct sockaddr *)&self->address,
		sizeof(self->address));
	return (res);
}
