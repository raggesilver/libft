# t_string

This is my implementation of a "string class" in c.

## Notes

All `steal` functions in commits after [df19f714](https://gitlab.com/raggesilver-42/libft/commit/df19f7141d6fde1e0ffcffb0bf8a49881741f911) should have the sufix `_s` and nothing else. For example:

- `ft_string_new_steal` -> `ft_string_new_s`
- `ft_string_{ap,pre,in}pend_steal` -> `ft_string_{ap,pre,in}pend_s`

Although it is highly recommended, having steal functions in separate files is not required.
