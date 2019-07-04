
# Libft

This is my libft (first project @ [42](https://www.42.us.org/) - grade `125%`). My libft now has way more than the required for the initial project and may not pass it anymore due to forbidden functions or something.

All the code follows the [Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf) and probably respects the following clause:
>All #define created to bypass the norm and/or obfuscate code are forbidden. This point must be checked by a human

## My additions

> Norm - A typedef’s name must start by t_

> Me - A static function name must start with fk_

> Me - "implementation" for datatypes in the documentation means it's about the closest I could get a struct to work like a class in C

> Me - `*_new` malloc's stuff, `*_destroy` free's stuff (for struct pointers of course)

> Me - The term inpend is something only the most cleaver people can understand, and those who claim "insert" is a better word are wrong

> Me - `t_ull` is a typedef for `unsigned long long`

**Summary**
1. [t_array](#t_array) a dynamic array implementation
	- [ft_array_new](#ft_array_new) instantiate an array
	- [ft_array_new_with_values](#ft_array_new_with_values) instantiate an array with values
	- [ft_array_destroy](#ft_array_destroy) destroy an array
	- [ft_array_terminate](#ft_array_terminate) terminate an array
	- [ft_array_push](#ft_array_push) push an element to an array
	- [ft_array_remove](#ft_array_remove) remove an element from an array
	- [ft_array_delete](#ft_array_delete) delete an element from an array
1. [t_string](#t_string) a string implementation
	- [ft_string_new](#ft_string_new) instantiate a string
	- [ft_string_new_s](#ft_string_new_s) instantiate a string by stealing a `char *`
	- [ft_string_destroy](#ft_string_destroy) destroy a string
	- [ft_string_append](#ft_string_append) append text to a string
	- [ft_string_prepend](#ft_string_prepend) prepend text to a string
	- [ft_string_inpend](#ft_string_inpend) inpend text to a string
	- [ft_string_remove](#ft_string_remove) remove text from a string
	- [ft_string_to_lower](#ft_string_to_lower) lowercase a string
	- [ft_string_to_upper](#ft_string_to_upper) uppercase a string
	- [ft_string_padding](#ft_string_padding) add a character padding to a string
1. [t_bignum](#t_bignum) an "infinite" bignum implementation*
	- [ft_bignum_new](#ft_bignum_new) instantiate a bignum
	- [ft_bignum_new_s](#ft_bignum_new_s) instantiate a bignum by stealing a `char *`
	- [ft_bignum_destroy](#ft_bignum_destroy) destroy a bignum
	- [ft_bignum_add](#ft_bignum_add) add an `int` to a bignum
	- [ft_bignum_real_add](#ft_bignum_real_add) add two bignums
	- [ft_bignum_mult](#ft_bignum_mult) multiply a bignum by a `t_ull`
	- [ft_bignum_div_10pow](#ft_bignum_div_10pow) divide a bignum by 10<sup>x</sup>
	- [ft_bignum_mult_10pow](#ft_bignum_mult_10pow) multiply a bignum by 10<sup>x</sup>
	- [ft_bignum_set](#ft_bignum_set) change the value of a bignum
	- [ft_bignum_set_decimal_padding](#ft_bignum_set_decimal_padding) set minimum number of decimal places for a bignum
	- [ft_bignum_set_whole_padding](#ft_bignum_set_whole_padding) set minimum number of digits in the whole part of a bignum
1. [ft_printf()](#ft_printf) my implementation of printf

---
### t_array
> Me - I'll do this soon...

---
### t_string
> Me - I'll do this soon...

---
### t_bignum
> *Implementing bignum operations is somewhat complicated and I haven't had the time to do it properly so operations may have flaws

> Me - I'll do this soon...

#### ft_bignum_set_decimal_padding()
**note**: does not decrease the number of decimal places

> Me - I'll do this soon...

#### ft_bignum_set_whole_padding()
**note**: does not decrease the number of digits in the whole part

> Me - I'll do this soon...

---
### ft_printf
> Moulinette - Final grade: 100
> Intra - Final Mark: 108
```C
size_t	ft_printf(const char *format, ...)
```
Does most of what prinft does when it is compiled with `-Wall -Werror -Wextra`. Has the bonus of colors which can be used as follows:
```C
ft_printf("{red}This is red, {bold}this is red and bold, {eoc}this is regular boring text\n");
```
Flags: + - 0 # * and space

Conversions: diouxXcspf

Sizes: l ll L h hh (L for floats only)

**note**: actual long doubles do work, LDBL_MAX and LDBL_MIN are covered!


## Credits
Thanks for [fprevela](https://github.com/prevelat) for coming up with the term "inpend".
