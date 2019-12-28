/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:13:58 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 16:02:31 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# if defined(_WIN32) || defined(_WIN64)
#  define FT_DIR_SEP '\\'
# else
#  define FT_DIR_SEP '/'
# endif

char	*ft_basename(const char *path);

#endif
