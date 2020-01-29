<div align="center">
    <h1>
        <img src="https://imgur.com/wDuy8yC.png" width="128" /> Libft
    </h1>
    <h4>Essential C library</h4>
    <p>
        <a href="https://gitlab.com/raggesilver-42/libft/pipelines">
            <img src="https://gitlab.com/raggesilver-42/libft/badges/master/pipeline.svg" alt="Build Status" />
        </a>
        <a href="https://www.patreon.com/raggesilver">
            <img src="https://img.shields.io/badge/patreon-donate-orange.svg?logo=patreon" alt="My profile on Patreon" />
        </a>
    </p>
    <p>
        <a href="#compile">Compile</a> •
        <a href="#use">Use</a> •
        <a href="https://gitlab.com/raggesilver-42/libft/blob/master/LICENSE">License</a> •
        <a href="#credits">Credits</a>
    </p>
</div>

This is my libft (first project at [42](https://www.42.us.org/) - graded `125%`).
My libft now has way more than the required for the initial project and **may not
pass Moulinette** due to forbidden functions or something.

My libft contains a few extra data types and functions I find useful. The
 project can be compiled both on OSX and Linux (for testing I use GCC >= 8).

All the code (including my additions) follow the
 [Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf).

## My additions

> Norm - A typedef’s name must start by t_

> Me - A static function name must start with fk_

> Me - "implementation" for datatypes in the documentation means it's about the closest I could get a struct to work like a class in C

> Me - `*_new` malloc's stuff, `*_destroy` free's stuff (for struct pointers of course)

> Me - The term inpend is something only the most clever people can understand, and those who claim "insert" is a better word are wrong

> Me - `t_ull` is a typedef for `unsigned long long`

> Me - src/list is where all my `t_list` functions are. Those are, however not the
> same as the required functions for the 42 Libft project. Those were removed on 2020-01-20.

**Summary**
1. [t_array](src/array/) a pointer array implementation
1. [t_string](src/string/) a string implementation
1. [t_bignum](src/bignum/) an "infinite" bignum implementation
1. [ft_printf()](src/ft_printf/) my implementation of printf

## Compile

```bash
# Make sure you are at the root of the project

# Regular make (very slow)
make

# Make with threads enabled (fastest)
make -j
```

All rules (re, fclean, clean) support the flag `-j`.

## Use

Making produces
```
.
├── build/    # Conatins object files and make rules for every object
├── includes/ # Contains all public headers
└── libft.a
```

If you're at 42 you probably shouldn't use someone else's libft, if you're not,
this is the way I add libft to my projects:

```bash
# Add libft as a submodule to your project
git submodule add git@gitlab.com:raggesilver-42/libft.git libft
# Then add libft to your makefile rules
```

---

## Credits
Thanks [fprevela](https://github.com/prevelat) for coming up with the term "inpend".

Functions based on other projects are properly attributed in their files.
