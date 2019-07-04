/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:30:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/22 16:59:22 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*g_colors[] = {
	"red", "\033[0;31m",
	"green", "\033[0;32m",
	"blue", "\033[0;34m",
	"white", "\033[0;37m",
	"black", "\033[0;30m",
	"darkgrey", "\033[1;30m",
	"purple", "\033[0;35m",
	"cyan", "\033[0;36m",
	"bold", "\033[1m",
	"eoc", "\033[0m",
	NULL
};

const int	g_color_sizes[] = {
	0, 7,
	0, 7,
	0, 7,
	0, 7,
	0, 7,
	0, 7,
	0, 7,
	0, 7,
	0, 4,
	0, 4,
	-1
};

static int	check_color(const char *str)
{
	char	*aux;
	int		i;

	RETURN_VAL_IF_FAIL(-1, (aux = ft_strchr(str, '}')));
	i = -1;
	while (g_colors[++i])
	{
		if (i % 2 != 0)
			continue ;
		if (ft_strncmp(g_colors[i], str, aux - str) == 0)
			return (i);
	}
	return (-1);
}

int			ftpf_print_color(const char **str, size_t *res)
{
	int c;

	if ((c = check_color(*str + 1)) < 0)
		return (0);
	*str += ft_strlen(g_colors[c]) + 2;
	*res += write(1, g_colors[c + 1], g_color_sizes[c + 1]);
	return (1);
}
