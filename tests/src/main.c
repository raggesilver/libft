/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:56:48 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/07/17 11:38:57 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

#include "libft.h"
#include "hashtable/ft_hashtable.h"
#include "../src/hashtable/ft_hashtable_priv.h"
#include "io/io.h"

#include "list/list.test.h"
#include "io_util/io.util.test.h"
#include "libc/libc.test.h"

typedef void (*test_function)();

static test_function *test_functions = (test_function[]){
	&list_test,
	&io_util_test,
	&libc_test,
	NULL
};

void arr_dest_func(void *el)
{
	ft_string_destroy((t_string **)&el);
}

int	main(void)
{
#ifdef T_STRING_STRESS_TEST
	// t_string stress test ====================================================
	{
		for (size_t i = 0; i < 5000; i++)
		{
			t_string *s = ft_string_new("batata is \"\"");
			ft_printf("'%s' Len: %lu\n", s->data, s->length);
			ft_string_append(s, ".");
			ft_printf("Append = ");
			ft_printf("'%s' Len: %lu\n", s->data, s->length);
			ft_string_inpend(s, 11, "goood");
			ft_printf("Inpend = ");
			ft_printf("'%s' Len: %lu\n", s->data, s->length);
			ft_string_prepend(s, "La ");
			ft_printf("Prepend = ");
			ft_printf("'%s' Len: %lu\n", s->data, s->length);
			ft_string_remove(s, 3, 6);
			ft_printf("Remove = ");
			ft_printf("'%s' Len: %lu\n", s->data, s->length);
			ft_string_inpend(s, 3, "potato");
			ft_printf("Inpend = ");
			ft_printf("'%s' Len: %lu\n", s->data, s->length);
			ft_string_to_upper(s);
			ft_printf("To upper = ");
			ft_printf("'%s' Len: %lu\n", s->data, s->length);
			for (size_t j = 0; j < 100; j++)
				ft_string_append(s, " blah blah aaasdasdasdasdasd asmdlk amsldk maklsmd lkams ldkmaslkdm alksm dmalks <<< end");
			ft_string_destroy(&s);
		}
	}
#endif
	// Test t_hashtable ========================================================
	{
		t_hashtable *ht = ft_hashtable_new();

		ft_printf("Hashtable size: %lu\nGrow hashtable\n", ht->size);
		ft_hashtable_grow(ht);
		ft_printf("Hashtable size: %lu\n", ht->size);

		ft_hashtable_insert(ht, "batata", ft_strdup("is good"));
		int *v = malloc(sizeof(*v));
		*v = 42;
		ft_hashtable_insert(ht, "bb", v);

		ft_printf("Val for %s => %d\n", "bb", *((int *)ft_hashtable_get(ht, "bb")));
		ft_printf("Val for %s => %s\n", "batata", (char *)ft_hashtable_get(ht, "batata"));

		ft_hashtable_delete(ht, "bb");
		char *s = ft_hashtable_remove(ht, "batata");
		ft_printf("Removed %s => %s\n", "batata", s);
		ft_strdel(&s);

		ft_printf("Hashtable length should be 0, it is: %lu\n", ht->length);

		ft_hashtable_terminate(&ht);
	}
	// Test ft_printf ==========================================================
	{
		ft_printf("Hello world!\n");
		ft_printf("'%d'\n", 42);
		ft_printf("'%x'\n", 42);
		ft_printf("'%X'\n", 42);
		ft_printf("'%o'\n", 42);
		ft_printf("'%i'\n", 42);
		ft_printf("'%f'\n", 42.42f);
		ft_printf("LDBL_MAX: '%Lf'\n", LDBL_MAX);
		t_string *s = ft_sprintf("42 + 0.42 = %.2f", 42.42);
		if (!ft_strequ(s->data, "42 + 0.42 = 42.42"))
		{
			ft_string_destroy(&s);
			ft_dprintf(2, "Error, ft_sprintf returned some doideira\n");
			return (1);
		}
		ft_printf("%s\n", s->data);
		ft_string_destroy(&s);
	}
	// Test t_file =============================================================
	{
		t_file f = ft_fopen("src/main.c", O_RDONLY);
		t_string *s = ft_fread(f);
		if (!s)
			ft_printf("Could not read file\n");
		else
			ft_printf("Read content from `main.c`\n%s", s->data);
		ft_string_destroy(&s);
		ft_fclose(f);
	}
	// Test t_string ===========================================================
	{
		t_string *s = ft_string_new("Batata is really good! ====== pad ======");
		ft_printf("%s\n", s->data);
		ft_string_padding(s, 0, 42, '*');
		ft_string_padding(s, s->length, 42, '*');
		ft_printf("%s\n", s->data);
		ft_string_destroy(&s);
	}
	// Test t_bignum ===========================================================
	{
		t_bignum *bn = ft_bignum_new("3.14159265359");
		ft_printf("Pi = %s\n", bn->str->data);
		ft_bignum_mult(bn, 999999);
		ft_printf("Pi * 999999 = %s\n", bn->str->data);
		ft_bignum_div_10pow(bn, 200);
		ft_printf("Pi * 999999 / (10^200) = %s\n", bn->str->data);
		ft_bignum_destroy(&bn);
	}
	// Test t_array ============================================================
	{
		t_array *arr = ft_array_new();
		ft_array_push(arr, ft_strdup("La batata 0"));
		ft_array_push(arr, ft_strdup("La batata 1"));
		ft_array_push(arr, ft_strdup("La batata 2"));
		ft_array_push(arr, ft_strdup("La batata 3"));
		ft_array_push(arr, ft_strdup("La batata 4"));
		ft_array_push(arr, ft_strdup("La batata 5"));
		ft_array_push(arr, ft_strdup("La batata 6"));
		ft_array_push(arr, ft_strdup("La batata 7"));
		ft_array_push(arr, ft_strdup("La batata 8"));
		ft_array_push(arr, ft_strdup("La batata 9"));
		char *s = ft_array_pop(arr);
		if (ft_strcmp("La batata 9", s) != 0)
		{
			ft_strdel(&s);
			ft_array_terminate(&arr);
			ft_printf("{red}ft_array_pop returned some doideira{eoc}\n");
			return (1);
		}
		ft_strdel(&s);
		size_t i = 0;
		while (i < arr->length)
		{
			ft_printf("arr[%lu]: %s\n", i, (char *)arr->data[i]);
			++i;
		}
		ft_array_terminate(&arr);
	}
	{
		t_array *arr = ft_array_new();

		ft_array_push(arr, ft_strdup("ccc"));
		ft_array_push(arr, ft_strdup("bbb"));
		ft_array_push(arr, ft_strdup("aaa"));

		ft_array_prepend(arr, ft_strdup("fff"));
		ft_array_insert(arr, 1, ft_strdup("eee"));
		ft_array_insert(arr, 2, ft_strdup("ddd"));

		ft_array_push(arr, ft_strdup("123"));

		for (size_t i = 0; i < arr->length; i++)
			ft_printf("Unsorted array[%lu] = '%s'\n", i, (char *)arr->data[i]);

		ft_array_sort(arr, (int (*)(void *, void *))&ft_strcmp);

		for (size_t i = 0; i < arr->length; i++)
			ft_printf("Sorted array[%lu] = '%s'\n", i, (char *)arr->data[i]);

		ft_array_terminate(&arr);
	}
	{
		char	**p = (char*[]){
			"/",
			"/home",
			"/home/",
			"/home/hacker",
			"/home/hacker/test.c",
			"/home/hacker/test/test",
			"/home/hacker/test/",
			".",
			"..",
			"../../something.c",
			"./Makefile",
			"batata.c",
			NULL
		};

		while (*p)
		{
			ft_printf("Basename for '%s' is '%s'\n", *p, ft_basename(*p));
			p++;
		}
	}
	// Test ft_strstr ==========================================================
	{
		const char *stacks[] = {
			"2022020", // 3
			"", // -1
			"222200000202000000", // 9
			"00000000000000200002000002020", // 26
			"202", // -1
			"0202", // -1
			NULL,
		};

		int res[] = {
			3, -1, 9, 25, -1, -1,
		};

		for (size_t i = 0; stacks[i] != NULL; i++) {
			const char *ptr = ft_strstr(stacks[i], "2020");
			const int	ires = (ptr) ? ptr - stacks[i] : -1;

			if (ires != res[i]) {
				ft_dprintf(
					STDERR_FILENO,
					"error ft_strstr: expected %d got %d for haystack '%s' and"
					"needle '2020'\n",
					res[i], ires, stacks[i]
				);
				return (1);
			}
		}
	}
	{
		for (size_t i = 0; test_functions[i]; i++)
			test_functions[i]();
	}
	ft_printf("Ran tests on Libft v%s!\n", LIBFT_VERSION);
	return (0);
}
