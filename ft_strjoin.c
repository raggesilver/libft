/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 23:30:11 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/15 23:56:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	RETURN_X_IF_NOT_Y(NULL, res);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	return (res);
}
