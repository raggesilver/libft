
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

		res = ft_strvstr(strv, str);
		assert(res == NULL);

		str = "first string";
		res = ft_strvstr(strv, str);
		assert(res == *strv);

		str = "";
		res = ft_strvstr(strv, str);
		assert(res == NULL);
	}
}
