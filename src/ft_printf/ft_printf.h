/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:11:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/05 16:05:14 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define _PF format(printf, 1, 2)

# include "../libft.h"
# include <stdarg.h>

enum			e_pflags
{
	HASH = 1,
	PLUS = 2,
	MINUS = 4,
	ZERO = 8,
	SPACE = 16,
	H = 32,
	HH = 64,
	L = 128,
	LL = 256,
	LONG_DOUBLE = 512
};

typedef struct	s_pinfo
{
	char		conv;
	int			flags;
	int			min_width;
	int			precision;
	int			fix;
	size_t		res;
}				t_pinfo;

int				ft_printf(const char *s, ...) __attribute__((_PF));

#endif
