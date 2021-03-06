/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:13:58 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 19:19:24 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

/*
** This is a collection of useful functions. At the moment they're mostly about
** files and paths.
*/

# if defined(_WIN32) || defined(_WIN64)
#  define FT_DIR_SEP '\\'
#  define FT_DIR_SEP_S "\\"
# else
#  define FT_DIR_SEP '/'
#  define FT_DIR_SEP_S "/"
# endif

char	*ft_basename(const char *path);
char	*ft_path_join(const char *first, ...);

#endif
