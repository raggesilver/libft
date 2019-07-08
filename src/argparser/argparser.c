/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:09:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/08 16:24:21 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

static t_arg	*fk_get_arg(t_arg **args, const char *str)
{
	ssize_t		i;

	i = -1;
	while (args[++i])
	{
		if (ft_strcmp(args[i]->str, str) == 0)
			return (args[i]);
	}
	return (NULL);
}

uint32_t		ft_parse_args(t_arg_parser *self)
{
	t_arg		*arg;

	self->flags = 0;
	while (*self->argv && **self->argv == '-')
	{
		if ((arg = fk_get_arg(self->args, *self->argv)))
			self->flags |= arg->val;
		else
		{
			(self->on_extra) ? self->on_extra(self) : 0;
			return (0);
		}
		self->argv++;
	}
	self->target = self->argv;
	return (self->flags);
}
