# t_file

A non-malloc'ed structure that holds a pointer (**not a copy**) to a `path`, a file descriptor `fd`, and an integer `mode` containing the mode used to open the file (e.g O_RDWR).

```C
typedef struct  s_file
{
    char        *path;
    int         fd;
    int         mode;
}               t_file;
```

## Summary
- [ft_fopen](#ft_fopen)
- [ft_fread](#ft_fread)
- [ft_fwrite](#ft_fwrite)
- [ft_fclose](#ft_fclose)

## Functions

### ft_fopen
```C
t_file				ft_fopen(const char *path, int mode);
```

Return a `t_file` resulted from opening `path` in mode `mode`.

> `ft_fopen` uses `open`

### ft_fread
```C
t_string			*ft_fread(t_file file);
```

Return a `t_string *` containing the contents of the file `file`.

> `ft_fread` uses `read`

### ft_write
```C
ssize_t				ft_fwrite(t_file file, t_string *str);
```

Write the contents of `str` to the file `file`.

> `ft_fwrite` uses `write`

### ft_close
```C
void				ft_fclose(t_file file);
```

Call close on `file.fd`.

> `ft_fclose` uses `close`