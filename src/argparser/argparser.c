/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:09:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/08 15:50:16 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

static t_arg	*fk_get_arg(t_arg **args, const char *str)
{
	size_t		i;

	i = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i]->str, str) == 0)
			return (args[i]);
		args++;
		i++;
	}
	return (NULL);
}

uint32_t		ft_parse_args(t_arg_parser *self)
{
	t_arg		*arg;

	self->flags = 0;
	while (*self->argv)
	{
		if ((arg = fk_get_arg(self->args, *self->argv)))
			self->flags |= arg->val;
		else if (**self->argv != '-' && self->target && !*self->target)
			*self->target = *self->argv;
		else if (self->on_extra)
		{
			self->on_extra(self);
			return (0);
		}
		self->argv++;
	}
	return (self->flags);
}
