# ArrayT (set of macros)

This is a set of macros created to make it easier to use type-safe arrays with any type in C. The generic struct created by the macro looks like this:

```c
struct // The struct is anonymous
{
    Type    *data;
    size_t  length;
    size_t  size;
}
```

## Example

```c
int main(void)
{
    // Declare an arrayt instance with an `int *data` field
    ARRAYT(int) *arr;

    // Initialize the array (malloc it)
    ARRAYT_INIT(arr);
    // Push values to the array
    ARRAYT_PUSH(arr, 42);
    ARRAYT_PUSH(arr, 43);
    ARRAYT_PUSH(arr, 44);
    // arr->data currently is [ 42, 43, 44 ]
    // Insert a value into a specific array position `i`
    // Note that `i` has to be < arr->length
    ARRAYT_INSERT(arr, 1, -42);
    // arr->data currently is [ 42, -42, 43, 44 ]
    ARRAYT_REMOVE(arr, 2);
    // arr->data currently is [ 42, -42, 44 ]
    // free the array
    ARRAYT_DESTROY(arr);
    return (0);
}
```

## Summary

- [ARRAYT](#arrayt)
- [ARRAYT_INIT](#arrayt_init)
- [ARRAYT_PUSH](#arrayt_push)
- [ARRAYT_PREPEND](#arrayt_prepend)
- [ARRAYT_INSERT](#arrayt_insert)
- [ARRAYT_REMOVE](#arrayt_remove)
- [ARRAYT_DESTROY](#arrayt_destroy)
- [ARRAYT_DESTROY_WITH_FUNC](#arrayt_destroy_with_func)

## Macros

### ARRAYT
```c
ARRAYT(Type)
```
Declare an anonymous array struct with `Type` as the data field.

Example:
```c
ARRAYT(int) *arr;
// Translates to
struct { int *data; size_t length; size_t size; } *arr;
```

### ARRAYT_INIT
```c
// void arrayt_init(void *arr)
ARRAYT_INIT(arr)
```
Instantiate a previously declared array.

### ARRAYT_PUSH
```c
ARRAYT_PUSH(arr, val)
```
Push a value `val` to `arr`.

### ARRAYT_PREPEND
```c
ARRAYT_PREPEND(arr, val)
```
Add a value `val` to the begining of the array.

### ARRAYT_INSERT
```c
ARRAYT_INSERT(arr, i, val)
```
Insert a value `val` into the array `arr` at index `i`.

### ARRAYT_REMOVE
```c
ARRAYT_REMOVE(arr, i)
```
Remove the value at index `i` from the array `arr`.

**Note**: This does not free the element. You have to do that yourself.

### ARRAYT_DESTROY
```c
ARRAYT_DESTROY(arr)
```
Free the array.

**Note**: This does not free the elements (if they were malloc'ed), only the array which holds them.

### ARRAYT_DESTROY_WITH_FUNC
```c
ARRAYT_DESTROY_WITH_FUNC(arr, func)
```
Call the function `func` for each element in the array, passing a void pointer to it, then free the array as in [ARRAYT_DESTROY](#arrayt_destroy)
