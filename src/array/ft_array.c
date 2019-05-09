/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:17:58 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/08 22:59:53 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_array	*ft_array_new(void)
{
	t_array *self;

	self = malloc(sizeof(*self));
	self->data = NULL;
	self->length = 0;
	self->size = 0;
	return (self);
}

t_array	*ft_array_new_with_values(void **values)
{
	t_array *self;

	self = ft_array_new();
	while (values && *values)
		ft_array_push(self, *values++);
	return (self);
}

void	ft_array_destroy(t_array **self)
{
	if ((*self)->data)
		free((*self)->data);
	free(*self);
	*self = NULL;
}

void	ft_array_terminate(t_array **self)
{
	size_t i;

	i = 0;
	while (i < (*self)->length)
		ft_memdel((*self)->data + i++);
	ft_array_destroy(self);
}
