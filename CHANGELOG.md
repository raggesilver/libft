# Changelog

## Unreleased - 2019-07-14

### Added
- Most likely added bugs to fix later
- `ft_int.h` is a header that contains some important integer typedefs (for most cases `stdint.h` is not necessary anymore)

### Updated
- A couple of functions received `__attribute__((pure))` which according to GCC's documentation **could make them faster** (these functions include `ft_strlen` and `ft_strcmp`)

### Removed
- `ft_array_append` had to be removed because of norm
- `t_ull` was removed

## Unreleased - 2019-07-12

### Added
- Most likely added bugs to fix later
- `ft_array_append` is an alias to `ft_array_push`

### Updated
- `t_array`'s header definitions are now in a separate file.
- `t_array->data` is now null-terminated

### Incompatible
- `ft_array_new_with_values` now takes two parameters and it's new prototype is:

```C
t_array *ft_array_new_with_values(void **values, ssize_t n);
// If `n` is -1 `values` has to be null-terminated
```

### Deprecated
- `ft_realloc` was deprecated and will stay deprecated until I implement my own `malloc`. As a side note `ft_reallocsz` is still available and flawless(ish)

-----

## Unreleased - 2019-07-09

### Added
- Most likely added bugs to fix later

### Incompatible
- All `t_file` functions were changed, this means no compatibility with any previous version. Essentially **`t_file` functions do not malloc anymore**, they all return a copy of `t_file`
