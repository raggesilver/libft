/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:11:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 16:02:38 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "util.h"

/*
** FIXME: this will most likely fail on Windows as I don't treat C:\ any
** differently from the rest
*/

char	*ft_basename(const char *path)
{
	t_string	*str;
	char		*res;
	char		*s;

	str = ft_string_new(path);
	if (str->length <= 1)
		res = (path) ? ft_strdup(path) : NULL;
	else
	{
		if (str->data[str->length - 1] == FT_DIR_SEP)
			ft_string_remove(str, str->length - 1, 1);
		s = str->data + str->length - 1;
		while (s > str->data && *s != FT_DIR_SEP)
			--s;
		if (s == str->data && (res = str->data))
			str->data = NULL;
		else
			res = (*(++s)) ? ft_strdup(s) : NULL;
	}
	ft_string_destroy(&str);
	return (res);
}
