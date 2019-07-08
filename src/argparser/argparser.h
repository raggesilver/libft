/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:50:07 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/08 16:06:36 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSER_H
# define ARGPARSER_H

# include "../libft.h"
# include <stdint.h>

typedef struct s_arg_parser	t_arg_parser;
typedef struct s_arg		t_arg;

typedef	void				(*t_argparser_callback)(t_arg_parser *self);

struct						s_arg_parser
{
	uint32_t				flags;
	t_arg					**args;
	const char				**target;
	const char				**argv;
	t_argparser_callback	on_extra;
};

struct						s_arg
{
	char					*str;
	uint32_t				val;
	t_argparser_callback	on_error;
};

uint32_t					ft_parse_args(t_arg_parser *self);

#endif
