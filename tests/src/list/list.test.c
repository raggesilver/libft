
// Tests for t_list
#include "list.test.h"

#include "libft.h"
#include <assert.h>

static int int_cmp(int *_a, int *_b)
{
	int a = *_a;
	int b = *_b;

	if (a == b) return (0);
	if (a < b) return (-1);
	return (1);
}

void list_test()
{
	{
		int my_grade = -42;
		int her_grade = 125;

		t_list *head = ft_list_new(&my_grade);
		ft_list_append(&head, &her_grade);

		assert(ft_list_get_item(head, 0));
		assert(*((int *)ft_list_get_item(head, 0)) == -42);

		assert(ft_list_get_item(head, 1));
		assert(*((int *)ft_list_get_item(head, 1)) == 125);

		ft_list_sort(&head, (t_compare_func)&int_cmp);

		assert(ft_list_get_item(head, 0));
		assert(*((int *)ft_list_get_item(head, 0)) == 125);

		assert(ft_list_get_item(head, 1));
		assert(*((int *)ft_list_get_item(head, 1)) == -42);

		ft_list_destroy(&head);
	}
	{
		char *a = ft_strdup("aaaa");
		char *b = ft_strdup("bbbb");

		t_list *head = ft_list_new(b);
		ft_list_append(&head, a);

		assert(b == ft_list_get_item(head, 0));
		assert(a == ft_list_get_item(head, 1));

		ft_list_rsort(&head, (t_compare_func)&ft_strcmp);

		assert(a == ft_list_get_item(head, 0));
		assert(b == ft_list_get_item(head, 1));

		ft_list_terminate(&head);
	}
}
