/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:10:58 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/05 17:30:23 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** i = index to inpend
** s = length of chars to inpend
** c = the char used to fill the string
*/

t_string	*ft_string_padding(t_string *self, size_t i, size_t s, char c)
{
	char str[s + 1];

	str[s] = 0;
	ft_memset(str, c, s);
	ft_string_inpend(self, i, str);
	return (self);
}
