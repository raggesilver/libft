/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delegates.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:21:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 18:54:17 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DELEGATES_H
# define FT_DELEGATES_H

/*
** Function typedefs ===========================================================
*/

typedef void		(*t_destroy_func)(void *obj);
typedef int			(*t_compare_func)(void *a, void *b);
typedef void		(*t_foreach_func)(void *el);
typedef void		*(*t_map_func)(void *el);

#endif
