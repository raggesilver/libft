# t_bignum

An "infinite" bignum implementation*.

> *Implementing bignum operations is somewhat complicated and I haven't had the time to do it properly so operations may have flaws

**Summary**

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

> Me - I'll do this soon...
