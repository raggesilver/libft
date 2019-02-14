/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:06:31 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/14 14:18:38 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char *tmp;

    tmp = NULL;
    while (*s) {
        if (*s == (char)c)
            tmp = (char *)s;
        s++;
    }
    if (c == 0)
        return ((char *)s);
    return (tmp);
}
