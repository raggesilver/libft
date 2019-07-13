# Changelog

## Unreleased - 2019-07-12

### New
- `ft_array_append` is an alias to `ft_array_push`

### Updated
- `t_array`'s header definitions are now in a separate file.
- `t_array->data` is now null-terminated

### Incompatible
- `ft_array_new_with_values` now takes to parameters and it's new prototype is:

```C
t_array *ft_array_new_with_values(void **values, ssize_t n);
// If `n` is -1 `values` has to be null-terminated
```

### Deprecated
- `ft_realloc` was deprecated and will stay deprecated while I don't have my own implementation of `malloc`. As a side note `ft_reallocsz` is still available and flawless(ish)

-----

## Unreleased - 2019-07-09

### Incompatible
- All `t_file` functions were changed, this means no compatibility with any previous version. Essentially **`t_file` functions do not malloc anymore**, they all return a copy of `t_file`
