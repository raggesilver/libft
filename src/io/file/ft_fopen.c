/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:44:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/09 00:02:38 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_file		ft_fopen(const char *path, int mode)
{
	t_file	f;

	f.path = path;
	f.fd = open(path, mode);
	f.mode = mode;
	return (f);
}
