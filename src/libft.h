/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:22 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/08 23:42:15 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define _IW2(x) (x == '\r' || x == '\v' || x == '\f')

# define IS_WHITESPACE(x) (x == ' ' || x == '\t' || x == '\n' || _IW2(x))

# define RETURN_IF_FAIL(x) ({ if (!x) return ; })
# define RETURN_VAL_IF_FAIL(x, y) ({ if (!y) return (x); })
# define CONTINUE_IF_FAIL(x) ({ if (!x) continue ; })

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define BUFF_SIZE 32

void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strtrim(char const *s);
size_t				ft_strlen(const char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);

/*
** Extras ======================================================================
*/

void				*ft_realloc(void *ptr, size_t len);
void				*ft_reallocsz(void *ptr, size_t len, size_t new_len);
char				*ft_strndup(const char *s, size_t len);
int					ft_int_len(int n);
int					ft_int_len_base(int n, int base);
char				*ft_itoa_base(int n, int base);
char				*ft_strdupchr(const char *str, char c);
int					ft_sqrt_ceil(int n);
size_t				ft_strchrcnt(const char *s, char c);

/*
** List type ===================================================================
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list *head, void *content, size_t s);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lst_set_head_index(t_list **alst, size_t index);
void				ft_lst_sort(t_list **alst, int (*cmp)(void *, void *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstcnt(t_list *head);

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

t_file				*ft_fopen(const char *path, int mode);
void				ft_fclose(t_file *f);
void				ft_fdestroy(t_file *f);
t_string			*ft_fread(t_file *self);
int					ft_fwrite(t_file *self, t_string *s);

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
	void			**data;
	size_t			length;
	size_t			size;
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

# define _AUTOMAL(x) ({ typeof(x) *pp_f = malloc(sizeof(x)); pp_f; })
# define AUTOPTR(x) ({ typeof(x) *pp_f = _AUTOMAL(x); *pp_f = x; pp_f; })

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