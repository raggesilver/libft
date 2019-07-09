/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:59:32 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/09 00:02:38 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

ssize_t		ft_fwrite(t_file file, t_string *str)
{
	RETURN_VAL_IF_FAIL(0, ((file.mode & O_WRONLY) || (file.mode & O_RDWR)));
	return (write(file.fd, str->data, str->length));
}
