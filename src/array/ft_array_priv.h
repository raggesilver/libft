/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_priv.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 01:30:20 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/27 01:58:47 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_PRIV_H
# define FT_ARRAY_PRIV_H

# include "ft_array.h"

void	ft_array_grow(t_array *self);
void	ft_array_shift(t_array *self, size_t start);
void	ft_array_shrink(t_array *self);
void	ft_array_maybe_shrink(t_array *self);

#endif
