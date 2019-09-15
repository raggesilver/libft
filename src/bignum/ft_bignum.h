/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:13:15 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/15 13:14:08 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGNUM_H
# define FT_BIGNUM_H

# include "../ft_int.h"
# include "../string/ft_string.h"

/*
** Bignum type =================================================================
*/

extern const char	*g_chars;

# define _FK_NBNSTR(x) ({ (t_string){(char *)x->str, x->length, NULL, NULL}; })
# define BN_TO_STRING(x) ({ t_string s = _FK_NBNSTR(x); &s; })

typedef struct		s_bignum
{
	t_string		*str;
	ssize_t			point;
}					t_bignum;

t_bignum			*ft_bignum_div_10pow(t_bignum *self, size_t n);
t_bignum			*ft_bignum_mult_10pow(t_bignum *self, size_t n);
t_bignum			*ft_bignum_mult(t_bignum *self, t_ullong n);
t_bignum			*ft_bignum_new_s(const char *str);
t_bignum			*ft_bignum_new(const char *str);
t_bignum			*ft_bignum_real_add(t_bignum *self, t_bignum *num);
t_bignum			*ft_bignum_set_decimal_padding(t_bignum *self, size_t s);
t_bignum			*ft_bignum_set_whole_padding(t_bignum *self, size_t s);
t_bignum			*ft_bignum_set(t_bignum *self, const char *s);
t_string			*ft_bignum_add(t_string *self, int n);
void				ft_bignum_destroy(t_bignum **self);

#endif
