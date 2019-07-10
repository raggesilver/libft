/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_priv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:58:27 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/09 16:26:07 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_PRIV_H
# define FT_STRING_PRIV_H

# include "ft_string.h"

# ifndef STRING_GROW_SIZE
#  define STRING_GROW_SIZE 100
# endif

size_t						ft_strdupsz(char **dest, const char *s);
void						ft_string_grow(t_string *self, size_t add_len);
size_t						fk_min_size(
								size_t mode, size_t size, size_t min_len);

extern const t_string_cfg	g_str_cfg;

#endif
