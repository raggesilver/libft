/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:50:05 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 20:59:20 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

t_string	*ft_fread(t_file file)
{
	t_string	*res;
	char		tmp[BUFF_SIZE + 1];
	ssize_t		r;

	if (!((file.mode & O_RDONLY) == O_RDONLY || (file.mode & O_RDWR) == O_RDWR))
		return (NULL);
	res = ft_string_new_with_config(NULL, (t_string_cfg){
		.growmode=T_STRING_GROWMODE_QUADRATIC,
		.extra=100
	});
	while ((r = read(file.fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[r] = 0;
		ft_string_appendn(res, tmp, r);
	}
	if (res->length == 0 && r == -1)
	{
		ft_string_destroy(&res);
		return (NULL);
	}
	return (res);
}
