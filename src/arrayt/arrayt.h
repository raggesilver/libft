/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:18:04 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/15 22:38:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYT_H
# define ARRAYT_H

# include "../libft.h"

void	arrayt_grow(void **data, size_t dsize, size_t *size);
void	arrayt_destroy(void **self, void **data);

# define ARRAY_T(T)			struct { T *data; size_t length; size_t size; }
# define ARRAYT_INIT(arr)	({ arr = ft_memalloc(sizeof(*arr)); })

/*
** ArrayT grow
*/

# define _A_GRW_1			(void **)&arr->data, sizeof(*arr->data), &arr->size
# define _A_GRW(arr)		({ arrayt_grow(_A_GRW_1); })

/*
** ArrayT maybe grow
*/

# define _ARRAYT_MGROW(arr)	({ if (arr->length + 1 > arr->size) _A_GRW(arr); })

/*
** ArrayT push
*/

# define _A_PSH_1(val)		({ arr->data[arr->length++] = val; })
# define _A_PSH(arr, val)	({ _ARRAYT_MGROW(arr); _A_PSH_1(val); })
# define ARRAYT_PUSH(arr, val) _A_PSH(arr, val)

/*
** ArrayT destroy
*/

# define _A_DTR(arr) ({ arrayt_destroy((void **)&arr, (void **)&arr->data); })
# define ARRAYT_DESTROY(arr) ({ _A_DTR(arr); })

#endif
