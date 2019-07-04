/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:14:31 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 16:35:35 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H

# include "../libft.h"

/*
** The amount of slots to allocate on grow.
** You may change this during compile by adding the flag -DHASHTABLE_SIZE=n
*/

# ifndef HASHTABLE_SIZE
#  define HASHTABLE_SIZE 50
# endif

/*
** If true (1) hashtable will double size on grow.
** You may change this during compile by adding the flag -DHASHTABLE_DOUBLE=1
*/

# ifndef HASHTABLE_DOUBLE
#  define HASHTABLE_DOUBLE 0
# endif

typedef struct	s_hashtable
{
	size_t		size;
	size_t		length;
	void		**values;
}				t_hashtable;

size_t			ft_hash(const char *key, const size_t size);
t_hashtable		*ft_hashtable_new();
void			ft_hashtable_destroy(t_hashtable **self);
void			ft_hashtable_terminate(t_hashtable **self);

#endif
