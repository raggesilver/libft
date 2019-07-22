# t_string

This is my implementation of a "string class" in c. The `t_string` type was designed to reduce the need to make many `ft_strlen` calls as the struct holds the string length itself. It also reduces the need to `realloc` data every time the string grows/shrinks (this is achieved by allocating larger amounts of memory than necessary). There are also a few useful functions to modify the string allowing insertion and removal of text at any index.

## Summary

- [ft_string_new](#ft_string_new)
- [ft_string_new_s](#ft_string_new_s)
- [ft_string_new_with_config](#ft_string_new_with_config)
- [ft_string_clone](#ft_string_clone)
- [ft_string_append](#ft_string_append)
- [ft_string_appendn](#ft_string_appendn)
- [ft_string_real_append](#ft_string_real_append)
- [ft_string_prepend](#ft_string_prepend)
- [ft_string_inpend](#ft_string_inpend)
- [ft_string_padding](#ft_string_padding)
- [ft_string_to_lower](#ft_string_to_lower)
- [ft_string_to_upper](#ft_string_to_upper)
- [ft_string_remove](#ft_string_remove)
- [ft_string_destroy](#ft_string_destroy)

## Functions

### ft_string_new
```C
t_string	*ft_string_new(const char *s)
```
Create a new `t_string *` from a given string `s` with default `t_string_cfg`. If `s` is `NULL` the default space will still be allocated.

### ft_string_new_s
```C
t_string	*ft_string_new_s(char **s)
```
Create a new `t_string *` from a given string pointer `s` with default `t_string_cfg`. `s` cannot be `NULL`. The new implementation doesn't allow the same pointer to be used. So this function creates the `t_string *` and calls `ft_strdel` on `s`.

### ft_string_new_with_config
```C
t_string	*ft_string_new_with_config(const char *s, t_string_cfg cfg)
```
Create a new `t_string *` from a given string `s` with `cfg` as config. If `s` is `NULL` the default space will still be allocated.

### ft_string_clone
```C
t_string	*ft_string_clone(const t_string *s)
```
Create a new `t_string *` by copying another `t_string *s`.

**Note**: the copy will have the same `t_string_cfg` as the original.

### ft_string_append
```C
t_string	*ft_string_append(t_string *self, const char *s)
```
Append a null-terminated string `s` to `self`.

### ft_string_appendn
```C
t_string	*ft_string_appendn(t_string *self, const char *s, size_t n)
```
Append `n` bytes of a string `s` to `self`. If `s` doesn't have `n` bytes the behavior is undefined.

### ft_string_real_append
```C
t_string	*ft_string_real_append(t_string *self, t_string *s)
```
Append `s->length` bytes to `self`.

### ft_string_prepend
```C
void		ft_string_prepend(t_string *self, const char *s)
```
Prepend `self` with a null-terminated string `s`.

### ft_string_inpend
```C
void		ft_string_inpend(t_string *self, size_t index, const char *str)
```
Inpend (insert) a null-terminated string `str` into `self` at index `index`.

If `index` is zero, the function will call `ft_string_prepend` and if `index` is greater than `self->length` it will call `ft_string_append`.

### ft_string_padding
```C
t_string	*ft_string_padding(t_string *self, size_t i, size_t s, char c)
```
Inpend `s` characters `c` to `self` at index `i`.

e.g.

```C
t_string *s = ft_string_new("blah");
ft_string_padding(s, 0, 10, 'J');
// s->data = "JJJJJJJJJJblah"
```

### ft_string_to_lower
```C
void		ft_string_to_lower(t_string *self)
```
Lowercase `self`.

### ft_string_to_upper
```C
void		ft_string_to_upper(t_string *self)
```
Upercase `self`.

### ft_string_remove
```C
t_string	*ft_string_remove(t_string *self, size_t index, size_t len)
```
Remove `len` bytes from `self` starting at index `index`.

`index`es longer than `self->length` are safely handled.

### ft_string_destroy
```C
void		ft_string_destroy(t_string **self)
```
Destroy (`free`) `*self` and point `self` to `NULL`.

----

## Dev notes

All `steal` functions in commits after [df19f714](https://gitlab.com/raggesilver-42/libft/commit/df19f7141d6fde1e0ffcffb0bf8a49881741f911) should have the sufix `_s` and nothing else. For example:

- `ft_string_new_steal` -> `ft_string_new_s`
- `ft_string_{ap,pre,in}pend_steal` -> `ft_string_{ap,pre,in}pend_s`

Although it is highly recommended, having steal functions in separate files is not required.
