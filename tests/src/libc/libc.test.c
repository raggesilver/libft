
#include "libft.h"
#include <assert.h>

void libc_test()
{
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
}
