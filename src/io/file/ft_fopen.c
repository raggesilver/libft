/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:44:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 20:59:17 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

t_file		ft_fopen(const char *path, int mode)
{
	t_file	f;

	f.path = path;
	f.fd = open(path, mode);
	f.mode = mode;
	return (f);
}
