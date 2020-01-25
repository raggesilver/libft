/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:22 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 21:03:06 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
** For file operations (open, create, etc.) and file permissions (O_RDWR, etc.)
*/

# include <fcntl.h>

# define IS_WHITESPACE	ft_iswhitespace
# define BUFF_SIZE		512

# undef FALSE
# define FALSE 0

# undef TRUE
# define TRUE 1

/*
** Libft types and macros ======================================================
*/

# include "ft_delegates.h"
# include "string/ft_string.h"
# include "array/ft_array.h"
# include "ft_int.h"
# include "ft_printf/ft_printf.h"
# include "list/ft_list.h"
# include "libc/libc.h"
# include "bignum/ft_bignum.h"
# include "util/util.h"

#endif
