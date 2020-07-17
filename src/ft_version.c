/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_version.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:52:19 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/07/17 11:36:37 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int __attribute__((const))
	ft_version_cmp(int major, int minor, int patch)
{
	if (major != LIBFT_VERSION_MAJOR)
		return (major - LIBFT_VERSION_MAJOR);
	if (minor != LIBFT_VERSION_MINOR)
		return (minor - LIBFT_VERSION_MINOR);
	return (patch - LIBFT_VERSION_PATCH);
}

int
	ft_version_cmps(char *version)
{
	int	major;
	int	minor;
	int	patch;

	major = ft_atoi(version);
	version = ft_strchr(version, '.') + 1;
	minor = ft_atoi(version);
	version = ft_strchr(version, '.') + 1;
	patch = ft_atoi(version);
	return (ft_version_cmp(major, minor, patch));
}

/*
** Example: ensuring minimum libft version at compile time:
**
** #define LFTVMJ LIBFT_VERSION_MAJOR
** #define LFTVMN LIBFT_VERSION_MINOR
** #define LFTVPT LIBFT_VERSION_PATCH
**
** #if (LFTVMJ < 1 || LFTVMN < 1 || LFTVPT < 1)
** # error Libft version 1.1.1+ is required
** #endif
**
** #undef LFTVMJ
** #undef LFTVMN
** #undef LFTVPT
*/
