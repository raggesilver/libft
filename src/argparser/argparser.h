/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:50:07 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 17:33:55 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSER_H
# define ARGPARSER_H

# include "../libft.h"

typedef struct s_argparser	t_argparser;
typedef struct s_arg		t_arg;

typedef	void				(*t_argparser_callback)(t_argparser *self);

struct						s_argparser
{
	t_uint32				flags;
	t_arg					**args;
	const char				**target;
	const char				**argv;
	t_argparser_callback	on_extra;
};

struct						s_arg
{
	char					*str;
	t_uint32				val;
	t_argparser_callback	on_error;
};

t_uint32					ft_parse_args(t_argparser *self);

#endif
