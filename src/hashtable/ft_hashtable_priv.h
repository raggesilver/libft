/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_priv.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:57:57 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 19:29:33 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTABLE_PRIV_H
# define FT_HASHTABLE_PRIV_H

# include "ft_hashtable.h"

t_ht_item	*ft_ht_item_new(const char *key, void *val);
void		ft_ht_item_destroy(t_ht_item **self);
void		ft_ht_item_terminate(t_ht_item **self);
void		ft_hashtable_grow(t_hashtable *self);

#endif
