/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:22 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/16 18:06:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <netinet/in.h>
# include <sys/socket.h>

# include "string/ft_string.h"
# include "array/ft_array.h"
# include "ft_int.h"

# define _IW2(x)			(x == '\r' || x == '\v' || x == '\f')
# define IS_WHITESPACE(x)	(x == ' ' || x == '\t' || x == '\n' || _IW2(x))

# define CONTINUE_IF(cond)				({ if (cond) continue ; })
# define RETURN_IF(cond)				({ if (cond) return ; })
# define RETURN_VAL_IF(val, cond)		({ if (cond) return (val); })

# define CONTINUE_IF_FAIL(cond)			({ if (!cond) continue ; })
# define RETURN_IF_FAIL(cond)			({ if (!cond) return ; })
# define RETURN_VAL_IF_FAIL(val, cond)	({ if (!cond) return (val); })

# define MIN(x, y)	((x > y) ? y : x)
# define MAX(x, y)	((x > y) ? x : y)
# define MOD(x)		((x < 0) ? -x : x)

# define BUFF_SIZE	32

/*
** Function typedefs ===========================================================
*/

typedef void		(*t_destroy_func)(void *obj);

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
	uint64_t		mantissa;
	t_ldbl			dbl;
	unsigned		sign : 1;
}					t_float;

t_float				ft_float_new(long double n);

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);

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
t_string			*ft_ldtos(long double n, int precision);

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
** Extras ======================================================================
*/

int					ft_int_len_base(int n, int base);
int					ft_int_len(int n);
int					ft_sqrt_ceil(int n);
size_t				ft_ull_len_base(unsigned long long n, int base);
size_t				ft_ull_len(unsigned long long n);

/*
** List type ===================================================================
*/

typedef struct		s_list
{
	size_t			content_size;
	struct s_list	*next;
	void			*content;
}					t_list;

size_t				ft_lstcnt(t_list *head);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lst_set_head_index(t_list **alst, size_t index);
void				ft_lst_sort(t_list **alst, int (*cmp)(void *, void *));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list *head, void *content, size_t s);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lst_safe_append(
						t_list **head, void *content, size_t size);

/*
** File type ===================================================================
*/

typedef struct		s_file
{
	const char		*path;
	int				fd;
	int				mode;
}					t_file;

ssize_t				ft_fwrite(t_file file, t_string *str);
t_file				ft_fopen(const char *path, int mode);
t_string			*ft_fread(t_file file);
void				ft_fclose(t_file file);

/*
** This is get_next_line under a different name.
*/

int					ft_readln(const int fd, char **line);

/*
** Socket type =================================================================
*/

# define _S_SADDRIN struct sockaddr_in

typedef _S_SADDRIN	t_addr;

typedef struct		s_socket
{
	int				fd;
	t_addr			address;
}					t_socket;

t_socket			*ft_socket_new(void);
t_socket			*ft_socket_new_with_port(int port);
int					ft_socket_bind(t_socket *self);

/*
** Bignum type =================================================================
*/

extern const char	*g_chars;

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
