/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:11:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/22 17:30:17 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "util.h"

/*
** This is a slightly modified ft_strrchr that does not catch the last occurence
** if it is the last character of the string (in that case it uses the previous
** occurence, unless there was none, in which case the last character is used
** anyways).
*/

static char	*fk_strrchar_skip_last(const char *s, char c)
{
	char	*tmp;

	if (c == 0)
		return ((char *)s);
	tmp = NULL;
	while (*s)
	{
		if (*s == c && (*(s + 1) != 0 || !tmp))
			tmp = (char *)s;
		++s;
	}
	return (tmp);
}

/*
** ft_basename
**
** My implementation of unix's basename command (man basename).
**
** From https://unix.stackexchange.com/a/32834/346463, 4096 is the max file path
** on Linux, I know this is going to return a file/folder name (which should be
** at most 255 characters long) but this size is just to be safe. This function
** does not malloc the result. The result will be overwritten upon the next
** call, so if you need a copy use ft_strdup.
**
** @param {const char *} path the path to get the basename from.
** @returns {char *} a (weak) buffer containing the basename of the path.
*/

char		*ft_basename(const char *path)
{
	static char	buff[4097];
	const char	*p;
	char		*b;

	ft_memset(buff, 0, 4097);
	if ((p = fk_strrchar_skip_last(path, FT_DIR_SEP)))
	{
		if (*(p + 1))
			++p;
		b = buff;
		while (*p != 0 && (*p != FT_DIR_SEP || p == path))
			*b++ = *p++;
	}
	else
		ft_strcpy(buff, path);
	return (buff);
}
