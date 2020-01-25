/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:01:02 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 21:20:07 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_H
# define LIBC_H

/*
** These are the mandatory functions for the original libft. There might be a
** few extra and a few missing.
*/

# include "../libft.h"

/*
** Char ========================================================================
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_iswhitespace(char c);

/*
** Memory ======================================================================
*/

int					ft_memcmp(const void *s1,
						const void *s2, size_t n) __attribute__((pure));
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s,
						int c, size_t n) __attribute__((pure));
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_realloc(
						void *ptr, size_t len) __attribute__((deprecated));
void				*ft_reallocsz(void *ptr, size_t len, size_t new_len);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);

/*
** Put* ========================================================================
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);

/*
** String ======================================================================
*/

char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c) __attribute__((pure));
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strdupchr(const char *str, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strndup(const char *s, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_strcmp(
						const char *s1, const char *s2) __attribute__((pure));
int					ft_strequ(
						char const *s1, char const *s2) __attribute__((pure));
int					ft_strncmp(const char *s1,
						const char *s2, size_t n) __attribute__((pure));
int					ft_strnequ(char const *s1,
						char const *s2, size_t n) __attribute__((pure));
size_t				ft_strchrcnt(const char *s, char c) __attribute__((pure));
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s) __attribute__((pure));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** Conversion ==================================================================
*/

typedef union		u_ldbl
{
	long double		val;
	char			bytes[sizeof(long double)];
}					t_ldbl;

typedef struct		s_float
{
	short			exponent;
	t_uint64		mantissa;
	t_ldbl			dbl;
	unsigned		sign : 1;
}					t_float;

t_float				ft_float_new(long double n);

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);

int					ft_atoi_base(const char *str, int base);

char				*ft_itoa_base(int n, int base);
char				*ft_itoa(int n);
char				*ft_lltoa_base(long long n, int base);
char				*ft_lltoa(long long n);
char				*ft_ltoa_base(long n, int base);
char				*ft_ltoa(long n);
char				*ft_ulltoa_base(unsigned long long n, int base);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ultoa_base(unsigned long n, int base);
char				*ft_ultoa(unsigned long n);
char				*ft_utoa_base(unsigned n, int base);
char				*ft_utoa(unsigned n);

/*
** Extras ======================================================================
*/

int					ft_int_len_base(int n, int base);
int					ft_int_len(int n);
int					ft_sqrt_ceil(int n);
size_t				ft_ull_len_base(unsigned long long n, int base);
size_t				ft_ull_len(unsigned long long n);
t_string			*ft_ldtos(long double n, int precision);

/*
** This is get_next_line under a different name.
*/

int					ft_readln(const int fd, char **line);

#endif
