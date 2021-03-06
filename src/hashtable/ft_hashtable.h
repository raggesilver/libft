/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:14:31 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 23:30:07 by pqueiroz         ###   ########.fr       */
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
#  define HASHTABLE_SIZE 1000
# endif

/*
** If true (1) hashtable will double size on grow.
** You may change this during compile by adding the flag -DHASHTABLE_DOUBLE=1
*/

# ifndef HASHTABLE_DOUBLE
#  define HASHTABLE_DOUBLE 0
# endif

typedef struct	s_ht_item
{
	char		*key;
	void		*val;
}				t_ht_item;

typedef struct	s_hashtable
{
	size_t		size;
	size_t		length;
	t_ht_item	**values;
}				t_hashtable;

size_t			ft_hash(const char *key, const size_t size);
size_t			ft_hashtable_insert(
					t_hashtable *self, const char *key, void *value);
t_hashtable		*ft_hashtable_new(void);
void			*ft_hashtable_get(t_hashtable *self, const char *key);
void			*ft_hashtable_remove(t_hashtable *self, const char *key);
void			ft_hashtable_delete(t_hashtable *self, const char *key);
void			ft_hashtable_destroy(t_hashtable **self);
void			ft_hashtable_terminate(t_hashtable **self);

#endif
