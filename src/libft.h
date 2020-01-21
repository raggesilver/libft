/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:22 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/20 19:20:09 by pqueiroz         ###   ########.fr       */
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

# define IS_WHITESPACE	ft_iswhitespace
# define BUFF_SIZE		32

# undef FALSE
# define FALSE 0

# undef TRUE
# define TRUE 1

/*
** Function typedefs ===========================================================
*/

typedef void		(*t_destroy_func)(void *obj);
typedef int			(*t_compare_func)(void *a, void *b);
typedef void		(*t_foreach_func)(void *el);
typedef void		*(*t_map_func)(void *el);

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

typedef struct sockaddr_in	t_addr;

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
