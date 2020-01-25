/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:12:52 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 19:16:10 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOCKET_H
# define FT_SOCKET_H

/*
** For socket functions
*/

# include <netinet/in.h>
# include <sys/socket.h>

/*
** Socket type =================================================================
*/

typedef struct sockaddr_in	t_addr;

typedef struct				s_socket
{
	int						fd;
	t_addr					address;
}							t_socket;

t_socket					*ft_socket_new(void);
t_socket					*ft_socket_new_with_port(int port);
int							ft_socket_bind(t_socket *self);

#endif
