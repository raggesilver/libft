/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:59:32 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:48:04 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

ssize_t		ft_fwrite(t_file file, t_string *str)
{
	if (!((file.mode & O_WRONLY) || (file.mode & O_RDWR)))
		return (0);
	return (write(file.fd, str->data, str->length));
}
