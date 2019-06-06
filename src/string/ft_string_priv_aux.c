/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_priv_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:59:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/05 15:01:37 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

/*
** Helper function that dups a string and returns it's size without calling
** ft_strlen twice
*/

size_t	ft_strdupsz(char **dest, const char *s)
{
	size_t	res;
	char	*p;

	res = ft_strlen(s);
	*dest = malloc(sizeof(**dest) * (res + 1));
	p = *dest;
	while ((*p++ = *s++))
		;
	return (res);
}
