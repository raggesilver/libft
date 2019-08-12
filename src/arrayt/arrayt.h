/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:18:04 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/16 11:25:23 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYT_H
# define ARRAYT_H

# include "../libft.h"

/*
** For internal use
*/

void	arrayt_grow(void **data, size_t dsize, size_t *size);
void	arrayt_destroy(void **self, void **data);
void	arrayt_remove(char *data, size_t dsize, size_t *len, size_t i);
void	arrayt_make_room(char *data, size_t dsize, size_t *len, size_t i);

/*
** ArrayT type
*/

# define ARRAYT(T)			struct { T *data; size_t length; size_t size; }

/*
** Instantiate a new ArrayT
*/

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

# define _A_DTR_FN1 size_t i = 0; while (i < arr->length)
# define _A_DTR_FN(arr, fn) ({ _A_DTR_FN1 fn(&arr->data[i++]); _A_DTR(arr); })

/*
** Call func on each array element passing a pointer to the element.
*/

# define ARRAYT_DESTROY_WITH_FUNC(arr, func) ({ _A_DTR_FN(arr, func); })

/*
** Helper macro to unpack ArrayT members to function params
*/

# define _A_UPK (char *)arr->data, sizeof(*arr->data), &arr->length

/*
** ArrayT remove
*/

# define ARRAYT_REMOVE(arr, i)	({ arrayt_remove(_A_UPK, i); })

# define _A_MKR arrayt_make_room
# define _A_INS_3(arr, i, val)	arr->data[i] = val; arr->length++;
# define _A_INS_2(arr, i, val)	_A_MKR(_A_UPK, i); _A_INS_3(arr, i, val);
# define _A_INS_1(arr, i, val)	({ _ARRAYT_MGROW(arr); _A_INS_2(arr, i, val); })
# define _A_INS(arr, i, val) ({ if (i < arr->length) _A_INS_1(arr, i, val); })

/*
** ArrayT insert
*/

# define ARRAYT_INSERT(arr, i, val)	({ _A_INS(arr, i, val); })

/*
** ArrayT prepend
*/

# define ARRAYT_PREPEND(arr, val)	ARRAYT_INSERT(arr, 0, val)

#endif
