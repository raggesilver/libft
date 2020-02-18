
#include "libft.h"
#include <assert.h>

#undef strlcpy

/*
** Copyright (c) 1998, 2015 Todd C. Miller <Todd.Miller@courtesan.com>
** Copyright (c) 2020 Paulo Queiroz <pvaqueiroz@gmail.com>
**
** Permission to use, copy, modify, and distribute this software for any
** purpose with or without fee is hereby granted, provided that the above
** copyright notice and this permission notice appear in all copies.
**
** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
** WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
** MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
** ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
** WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
** ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
** OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
**
** This is a modified version of BSD's strlcpy used for testing purposes.
*/

size_t
	strlcpy(char *restrict dst, const char *restrict src, size_t dsize)
{
	const char	*osrc = src;
	size_t		nleft = dsize;

	nleft = dsize;
	if (nleft != 0) {
		while (--nleft != 0) {
			if ((*dst++ = *src++) == '\0')
				break;
		}
	}
	if (nleft == 0) {
		if (dsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return(src - osrc - 1);
}

void libc_test()
{
	// ft_strvstr
	{
		char *strv[] = {
			"first string",
			"second string",
			NULL,
		};

		char *str = "nope";
		char *res;
		size_t out;

		res = ft_strvstr(strv, str);
		assert(res == NULL);
		assert(ft_strv_index_of(strv, str) == -1);
		assert(ft_strv_get_index_of(strv, str, &out) == FALSE);

		str = "first string";
		res = ft_strvstr(strv, str);
		assert(res == *strv);
		assert(ft_strv_index_of(strv, str) == 0);
		assert(ft_strv_get_index_of(strv, str, &out) == TRUE);
		assert(out == 0);

		str = "";
		res = ft_strvstr(strv, str);
		assert(res == NULL);
		assert(ft_strv_index_of(strv, str) == -1);
		assert(ft_strv_get_index_of(strv, str, &out) == FALSE);
	}
	// ft_strlcpy
	{
		char *str = "abcdef";
		char tmp[20];
		char tmp2[20];
		size_t ft;
		size_t bsd;

		ft_bzero(tmp, 20);
		ft_bzero(tmp2, 20);
		ft = ft_strlcpy(tmp, str, 3);
		bsd = strlcpy(tmp2, str, 3);
		assert(ft == bsd);
		assert(ft_strequ(tmp, tmp2));

		ft_bzero(tmp, 20);
		ft_bzero(tmp2, 20);
		ft = ft_strlcpy(tmp, str, 20);
		bsd = strlcpy(tmp2, str, 20);
		assert(ft == bsd);
		assert(ft_strequ(tmp, tmp2));

		ft_bzero(tmp, 20);
		ft_bzero(tmp2, 20);
		ft = ft_strlcpy(tmp, str, 0);
		bsd = strlcpy(tmp2, str, 0);
		assert(ft == bsd);
		assert(ft_strequ(tmp, tmp2));
	}
}
