# ft_printf

**Summary**
1. [ft_printf()](#ft_printf) my implementation of printf

### ft_printf
> Final Mark: 108
```c
size_t	ft_printf(const char *format, ...)
```
Does most of what prinft does when it is compiled with `-Wall -Werror -Wextra`. Has the bonus of colors which can be used as follows:
```c
ft_printf("{red}This is red, {bold}this is red and bold, {eoc}this is regular boring text\n");
```
Flags: + - 0 # * and space

Conversions: diouxXcspf

Sizes: l ll L h hh (L for floats only)

**note**: actual long doubles do work, LDBL_MAX and LDBL_MIN are covered!
