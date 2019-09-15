/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:19:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/15 13:20:36 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include "file/ft_file.h"

/*
** Socket type =================================================================
*/

# define _S_SADDRIN struct sockaddr_in

typedef _S_SADDRIN	t_addr;

typedef struct		s_socket
{
	int				fd;
	t_addr			address;
}					t_socket;

t_socket			*ft_socket_new(void);
t_socket			*ft_socket_new_with_port(int port);
int					ft_socket_bind(t_socket *self);

#endif
