# Changelog

**Quick summary of keywords**
- **Added**: new feature
- **Removed**: removed feature
- **Updated**: updated feature, API (prototype and return) unchanged
- **Incompatible**: updated feature, API (prototype and/or return) changed
- **Deprecated**: still in code but should not be used anymore. Most likely a `__attribute__((deprecated))` was added to the code and it's use will generate compiler warnings

## Unreleased - 2020-01-24

### Added
- `ft_path_join`

### Updated/Incompatible
A lot of changes were made to libft's headers, now most of what one would expect
is available just by including `libft.h`.

- `ft_printf.h` is now included in libft.h
- `ft_delegates.h` is now included in libft.h
- `io/util.{c,h}` were moved to `util/util.{c,h}`
- `util/util.{c,h}` are now included in libft.h
- `<stdarg.h>` is now included in libft.h

## Unreleased - 2020-01-20

Introduced decent and usable list. Removed standard libft `t_list` functions.

### Removed
- All `ft_lst*` functions

### Added
- `ft_list_new`
- `ft_list_new_s`
- `ft_list_destroy`
- `ft_list_terminate`
- `ft_list_destroy_with_func`
- `ft_list_length`
- `ft_list_map`
- `ft_list_foreach`
- `ft_list_append`
- `ft_list_prepend`
- `ft_list_insert`
- `ft_list_get_index`
- `ft_list_get_last`
- `ft_list_get_item`
- `ft_list_get_last_item`
- `ft_list_remove`
- `ft_list_delete`
- `ft_list_delete_with_func`
- `ft_list_set_head_index`
- `ft_list_sort`
- `ft_list_rsort`

### Updated/Incompatible

The `t_list` struct has changed, it no longer has the `size_t content_size` field.
`t_list`s are also handled differently now. The original one from the PDF required
us to copy `content_size` bytes from `content`, which meant we were creating a hard
copy of the content. The current approach simply uses the given pointer (and does not
copy the contents).

## Unreleased - 2019-12-26

Freaking new norminette rule forbids macros with arguments and non-constant values.
Because of that ArrayT is retired and will most likely never come back.

### Removed

- All `ArrayT` related functions

### Added

- `ft_array_sort`

## Unreleased - 2019-07-22

### Updated
- `ft_string_new_s` now uses the same pointer given to the function

## Unreleased - 2019-07-14

### Added
- Most likely added bugs to fix later
- `ft_int.h` is a header that contains some important integer typedefs (for most cases `stdint.h` is not necessary anymore)
- `ft_dprintf`, `ft_sprintf`, `ft_vsprintf` and `ft_vdprintf` were added.
> **Important note**: my implementation of `ft_sprintf` and `ft_vsprintf` return a `t_string *`.

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

```c
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
