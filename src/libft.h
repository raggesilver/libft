/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:22 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/13 18:22:08 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define _IW2(x)			(x == '\r' || x == '\v' || x == '\f')
# define IS_WHITESPACE(x)	(x == ' ' || x == '\t' || x == '\n' || _IW2(x))

# define CONTINUE_IF_FAIL(x)		({ if (!x) continue ; })
# define RETURN_IF_FAIL(x)			({ if (!x) return ; })
# define RETURN_VAL_IF_FAIL(x, y)	({ if (!y) return (x); })

# define MIN(x, y)	((x > y) ? y : x)
# define MAX(x, y)	((x > y) ? x : y)
# define MOD(x)		((x < 0) ? -x : x)

# define BUFF_SIZE	32
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

# define _ULL unsigned long long

typedef _ULL		t_ull;

/*
** Conversion =====
*/

typedef union		u_ld_i64
{
	long double		f;
	int64_t			i;
	unsigned char	c[128];
}					t_u_ld_i64;

typedef struct		s_float
{
	// long			exp;
	// long			man;
	// uint64_t		den;
	// uint64_t		num;
	int64_t			mantissa;
	int16_t			exponent;
	t_u_ld_i64		un;
	int				sign : 1;
}					t_float;

t_float				ft_float_new(long double n);

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);

char				*ft_itoa_base(int n, int base);
char				*ft_itoa(int n);
char				*ft_ldtoa(long double n, int precision);
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
** Char =====
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** Memory =====
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_realloc(void *ptr, size_t len);
void				*ft_reallocsz(void *ptr, size_t len, size_t new_len);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);

/*
** Put* =====
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
** String =====
*/

char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
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
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strchrcnt(const char *s, char c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
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

/*
** String type =================================================================
*/

typedef struct		s_string
{
	char			*data;
	size_t			length;
	void			(*append)(struct s_string *self, const char *s);
	void			(*destroy)(struct s_string **self);
}					t_string;

# define T_STRING(x) ((t_string *)x)

t_string			*ft_string_new(const char *s);
void				ft_string_append(t_string *self, const char *s);
void				ft_string_destroy(t_string **self);
void				ft_string_inpend(t_string *self, size_t index,
										const char *str);
void				ft_string_prepend(t_string *self, const char *s);
void				ft_string_to_lower(t_string *self);
void				ft_string_to_upper(t_string *self);

/*
** File type ===================================================================
*/

typedef struct		s_file
{
	const char		*path;
	int				fd;
	int				mode;
}					t_file;

# define T_FILE(x) ((t_file *)x)

int					ft_fwrite(t_file *self, t_string *s);
t_file				*ft_fopen(const char *path, int mode);
t_string			*ft_fread(t_file *self);
void				ft_fclose(t_file *f);
void				ft_fdestroy(t_file *f);

/*
** This is get_next_line under a different name.
*/

int					ft_readln(const int fd, char **line);

/*
** Array type ==================================================================
*/

# define ARRAY_GROW_SIZE 10

typedef struct		s_array
{
	size_t			length;
	size_t			size;
	void			**data;
}					t_array;

# define T_ARRAY(x) ((t_array *)x)

t_array				*ft_array_new(void);

/*
** Push a value `void *value` to `t_array *self`
*/

void				ft_array_push(t_array *self, void *value);

/*
** AUTOPTR(x) is a macro that takes in any value, allocates a pointer
** that points to that value and returns the pointer. It is supposed to
** make life easier when adding simple datatypes like integers and floats
** to an array. This pointer can be freed manually or using `ft_array_terminate`
*/

# define _AUTOMAL(x)	({ typeof(x) *pp_f = malloc(sizeof(x)); pp_f; })
# define AUTOPTR(x)		({ typeof(x) *pp_f = _AUTOMAL(x); *pp_f = x; pp_f; })

/*
** This function initializes the array with values from a NULL terminated
** array of void pointers `void **values`.
*/

t_array				*ft_array_new_with_values(void **values);

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
** pointer or NULL if the indexdoesn't exist.
*/

void				*ft_array_remove(t_array *self, size_t index);

/*
** Delete (free) an index from the array if it exists and shift all following
** values to the left.
*/

void				ft_array_delete(t_array *self, size_t index);

#endif
