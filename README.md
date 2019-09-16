
# libft

This is my libft (first project at [42](https://www.42.us.org/) - graded `125%`).
My libft now has way more than the required for the initial project and may not
pass Moulinette due to forbidden functions or something.

My libft contains a few extra data types and functions I find useful. The
 project can be compiled both on OSX and Linux (for testing I use GCC >= 8).

All the code (including my additions) follow the
 [Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf) and probably respect
 the following clause:
>All #define created to bypass the norm and/or obfuscate code are forbidden.
>This point must be checked by a human

## My additions

> Norm - A typedef’s name must start by t_

> Me - A static function name must start with fk_

> Me - "implementation" for datatypes in the documentation means it's about the closest I could get a struct to work like a class in C

> Me - `*_new` malloc's stuff, `*_destroy` free's stuff (for struct pointers of course)

> Me - The term inpend is something only the most clever people can understand, and those who claim "insert" is a better word are wrong

> Me - `t_ull` is a typedef for `unsigned long long`

**Summary**
1. [Array\<T>](src/arrayt) typed dynamic array
1. [t_string](src/string/) a string implementation
1. [t_bignum](src/bignum) an "infinite" bignum implementation
1. [ft_printf()](src/ft_printf) my implementation of printf

---

## Credits
Thanks [fprevela](https://github.com/prevelat) for coming up with the term "inpend".

Functions based on other projects are properly attributed in each file.
