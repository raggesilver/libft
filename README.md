# Libft

This is my libft, containing all the required functions for `125% on 42 libft` plus additional funcions, structs and macros I find useful.

## My additions

*all `t_*` are typedef'd

### `t_string`

A struct that contains (mainly):

| member          | description              |
| --------------: | ------------------------ |
| `char *`data    | the string itself        |
| `size_t` length | the length of the string |

### `t_array`

An implementation of a dynamic array in C. It contains

| member          | description              |
| --------------: | ------------------------ |
| `void **`data   | an array of void pointers that contains tha array data |
| `size_t` length | the amount of elements in the array |
| `size_t` size   | the amount of "slots" allocated in the array |

The array has a few functions that may change the `t_array`'s `size`
- `ft_array_push`: add a `void *` to the array. Might allocate more `ARRAY_GROW_SIZE (10)` "slots" for `data`
- `ft_array_delete`, `ft_array_remove`: remove a value from the array by it's index. Might free `ARRAY_GROW_SIZE (10)` "slots" from `data`

### `t_file`

My implementation of libc's `FILE`. A struct that contains

| member          | description                    |
| --------------: | ------------------------------ |
| `int` fd        | the file descriptor            |
| `int` mode      | a sum of all open mode flags used to open the file |
| `char *`path    | the path used to open the file |
