/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:24:39 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/12 17:36:24 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "../libft.h"

/*
** AUTOPTR(x) is a macro that takes in any value, allocates a pointer
** that points to that value and returns the pointer. It is supposed to
** make life easier when adding simple datatypes like integers and floats
** to an array. This pointer can be freed manually or using `ft_array_terminate`
*/

# define _AUTOMAL(x)	({ typeof(x) *pp_f = malloc(sizeof(x)); pp_f; })
# define AUTOPTR(x)		({ typeof(x) *pp_f = _AUTOMAL(x); *pp_f = x; pp_f; })

# define ARRAY_GROW_SIZE 10

typedef struct		s_array
{
	size_t			length;
	size_t			size;
	void			**data;
}					t_array;

# define T_ARRAY(x) ((t_array *)x)

/*
** Instantiate an empty `t_array *`
*/

t_array				*ft_array_new(void);

/*
** Push `value` to `self`
*/

void				ft_array_push(t_array *self, void *value);

/*
** Alias to ft_array_push
*/

void				ft_array_append(t_array *self, void *value);

/*
** Instantiate a `t_array *` from an array of void pointers and a length `n`. If
** length `n` is -1 the array `values` must be null-terminated.
*/

t_array				*ft_array_new_with_values(void **values, ssize_t n);

/*
** This function frees the `self->data` array. The values themselves aren't
** freed.
*/

void				ft_array_destroy(t_array **self);

/*
** This function does everything `ft_array_destroy` does plus it frees all
** values in the array.
**
** Beware if you use the array to store structs calling this function will
** not free those structs' members, only their reference.
*/

void				ft_array_terminate(t_array **self);

/*
** Remove an index from the array and shift all following values, RETURN it's
** pointer or NULL if the index doesn't exist.
*/

void				*ft_array_remove(t_array *self, size_t index);

/*
** Remove and return the last value in the array. Returns NULL if there are no
** elements in the array.
*/

void				*ft_array_pop(t_array *self);

/*
** Delete (free) an index from the array if it exists and shift all following
** values.
*/

void				ft_array_delete(t_array *self, size_t index);

#endif
