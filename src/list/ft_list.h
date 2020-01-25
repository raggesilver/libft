/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:06:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 19:07:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "../ft_delegates.h"
# include <stdlib.h>

/*
** List type ===================================================================
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_list_new(void *content);
t_list				*ft_list_new_s(void **content);

/*
** ft_list_destroy will free the list and all it's elements, but not their
** content (for that either use ft_list_destroy_with_func or ft_list_terminate
** in case the elements only need to be free'd).
*/

void				ft_list_destroy(t_list **self);
void				ft_list_terminate(t_list **self);
void				ft_list_destroy_with_func(t_list **self, t_destroy_func fn);

size_t				ft_list_length(t_list *self);

t_list				*ft_list_map(t_list *self, t_map_func fn);
void				ft_list_foreach(t_list *self, t_foreach_func fn);

void				ft_list_append(t_list **self, void *content);
void				ft_list_prepend(t_list **self, void *content);
void				ft_list_insert(t_list **self, void *content, size_t index);

t_list				*ft_list_get_index(t_list *self, size_t index);
t_list				*ft_list_get_last(t_list *self);
void				*ft_list_get_item(t_list *self, size_t index);
void				*ft_list_get_last_item(t_list *self);

/*
** ft_list_remove free a list item and return it's contents. If the index does
** not exist return NULL.
*/

void				*ft_list_remove(t_list **self, size_t index);

/*
** ft_list_delete free's an item and it's contents. Should not be used if
** storing structures or pointers to primitive types (&int, &double, etc.).
** If the index does not exist nothing will be done.
*/

void				ft_list_delete(t_list **self, size_t index);
void				ft_list_delete_with_func(
						t_list **self, size_t index, t_destroy_func fn);

/*
** ft_list_set_head_index moves a node `index` from it's current position to the
** begining of the list. After the move the node before will point to the moved
** node's next and the list will have a new head.
*/

void				ft_list_set_head_index(t_list **self, size_t index);

void				ft_list_sort(t_list **self, t_compare_func fn);
void				ft_list_rsort(t_list **self, t_compare_func fn);

#endif
