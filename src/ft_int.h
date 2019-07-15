/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:22 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 22:17:53 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# ifndef INT_MAX
#  define INT_MAX				__INT_MAX__
# endif

# ifndef INT_MIN
#  define INT_MIN				-(__INT_MAX__ - 1)
# endif

# ifndef LONG_MAX
#  define LONG_MAX				__LONG_MAX__
# endif

# ifndef LONG_MIN
#  define LONG_MIN				-(__LONG_MAX__ - 1)
# endif

# ifndef LONG_LONG_MAX
#  define LONG_LONG_MAX			__LONG_LONG_MAX__
# endif

# ifndef LONG_LONG_MIN
#  define LONG_LONG_MIN			-(__LONG_LONG_MAX__ - 1)
# endif

# ifndef UINT8_MAX
#  define UINT8_MAX				__UINT8_MAX__
# endif

# ifndef UINT16_MAX
#  define UINT16_MAX			__UINT16_MAX__
# endif

# ifndef UINT32_MAX
#  define UINT32_MAX			__UINT32_MAX__
# endif

# ifndef UINT64_MAX
#  define UINT64_MAX			__UINT64_MAX__
# endif

typedef __INT8_TYPE__			t_int8;
typedef __INT16_TYPE__			t_int16;
typedef __INT32_TYPE__			t_int32;
typedef __INT64_TYPE__			t_int64;
typedef __int128_t				t_int128;

# ifdef __intmax_t

typedef __intmax_t				t_intmax;

# endif

# ifdef __uintmax_t

typedef __uintmax_t				t_uintmax;

# endif

typedef __UINT8_TYPE__			t_uint8;
typedef __UINT16_TYPE__			t_uint16;
typedef __UINT32_TYPE__			t_uint32;
typedef __UINT64_TYPE__			t_uint64;
typedef __uint128_t				t_uint128;

typedef __INT16_TYPE__			t_short;
typedef __UINT16_TYPE__			t_ushort;

typedef long int				t_long;
typedef unsigned long int		t_ulong;

typedef long long int			t_llong;
typedef unsigned long long int	t_ullong;

#endif