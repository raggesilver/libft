/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strv_index_of.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 02:13:41 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/02/01 02:21:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

ssize_t	ft_strv_index_of(char **strv, const char *str)
{
	size_t	i;

	i = 0;
	if (*str == 0)
		return (-1);
	while (strv[i])
	{
		if (ft_strequ(strv[i], str))
			return (i);
		++i;
	}
	return (-1);
}

int		ft_strv_get_index_of(char **strv, const char *str, size_t *out)
{
	size_t	i;

	i = 0;
	if (*str == 0)
		return (FALSE);
	while (strv[i])
	{
		if (ft_strequ(strv[i], str))
		{
			*out = i;
			return (TRUE);
		}
		++i;
	}
	return (FALSE);
}
