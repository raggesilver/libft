
// Tests for io/util

#include "io.util.test.h"
#include "util/util.h"
#include "libft.h"
#include <assert.h>

void io_util_test()
{
	{
		char *path = NULL;

		path = ft_path_join("/home/hacker", "Documents", "batata", NULL);
		ft_printf("Joined path '%s'\n", path);

		assert(ft_strequ(
			path,
			"/home/hacker" FT_DIR_SEP_S "Documents" FT_DIR_SEP_S "batata"
		));

		ft_strdel(&path);

		path = ft_path_join("/home/hacker", NULL);
		ft_printf("Joined path '%s'\n", path);

		assert(ft_strequ(path, "/home/hacker"));

		ft_strdel(&path);
	}
}
