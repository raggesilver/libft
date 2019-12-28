# t_array

This is my implementation of a pointer array in C. `t_array` grows and shrinks
on demand (based on `ARRAY_GROW_SIZE`).

## Fields

- `size_t length` - the amount of elements in the array
- `size_t size` - the number of elements that fit in the array (internal use)
- `void **data` - pointer array that stores the data

## Summary

- [ft_array_delete](#ft_array_delete) delete an element from an array
- [ft_array_destroy](#ft_array_destroy) destroy an array
- [ft_array_insert](#ft_array_insert) insert an element at an index of an array
- [ft_array_new_with_values](#ft_array_new_with_values) instantiate an array with values
- [ft_array_new](#ft_array_new) instantiate an array
- [ft_array_prepend](#ft_array_prepend) add an element to the begining of an array
- [ft_array_push](#ft_array_push) push an element to an array
- [ft_array_remove](#ft_array_remove) remove an element from an array
- [ft_array_terminate](#ft_array_terminate) terminate an array


## Functions

### ft_array_delete

Delete (free) and remove an element from an array at index `index` (shifts other
values).

```c
void ft_array_delete(t_array *self, size_t index);
```

### ft_array_destroy

Destroy the array (free). **Does not free the elements inside the array**.

```c
void ft_array_destroy(t_array **self);
```

### ft_array_insert

Insert an element at index `index`. If `index` < 0 `ft_array_prepend` will be
called, and if `index` >= `array->length` `ft_array_push` will be called.

```c
void ft_array_insert(t_array *self, size_t index, void *value);
```

### ft_array_new_with_values

Instanciate an array with `values`. If `n` is set, `n` elements will be copied
from `values` to `array->data` (fast), if it isn't `values` must be `null`
terminated so that all elements until `NULL` are `ft_array_push`'ed to the
array (slow).

```c
t_array *ft_array_new_with_values(void **values, ssize_t n);
```

### ft_array_new

Instanciate an empty array.

```c
t_array *ft_array_new(void);
```

### ft_array_prepend

Add an element at the begining of the array.

```c
void ft_array_prepend(t_array *self, void *value);
```

### ft_array_push

Add an element at the end of the array.

```c
void ft_array_push(t_array *self, void *value);
```

### ft_array_remove

Remove and return an element at index `index` from the array (does not free).

```c
void *ft_array_remove(t_array *self, size_t index);
```

### ft_array_terminate

Free all elements in the array, then `ft_array_destroy` it.

```c
void ft_array_terminate(t_array **self);
```
