/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:41:52 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/08/24 19:28:34 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "../libft.h"

enum					e_string_grow
{
	T_STRING_GROWMODE_FIXED,
	T_STRING_GROWMODE_DOUBLE,
	T_STRING_GROWMODE_QUADRATIC
};

typedef struct			s_string_cfg
{
	size_t				extra;
	short				growmode;
}						t_string_cfg;

typedef struct			s_string
{
	char				*data;
	size_t				length;
	size_t				size;
	const t_string_cfg	cfg;
}						t_string;

# define T_STRING(x) ((t_string *)x)

t_string				*ft_string_clone(const t_string *s);
t_string				*ft_string_new_n(const char *s, size_t size);
t_string				*ft_string_new_s(char **str);
t_string				*ft_string_new(const char *s);
t_string				*ft_string_new_with_config(
							const char *s, t_string_cfg cfg);
t_string				*ft_string_padding(
							t_string *self, size_t i, size_t s, char c);
t_string				*ft_string_remove(t_string *self, size_t index,
							size_t len);
void					ft_string_append(t_string *self, const char *s);
void					ft_string_appendn(
							t_string *self, const char *s, size_t n);
void					ft_string_destroy(t_string **self);
void					ft_string_inpend(t_string *self, size_t index,
										const char *s);
void					ft_string_prepend_s(t_string *self, char **s);
void					ft_string_prepend(t_string *self, const char *s);
void					ft_string_real_append(t_string *self, t_string *s);
void					ft_string_to_lower(t_string *self);
void					ft_string_to_upper(t_string *self);

#endif
