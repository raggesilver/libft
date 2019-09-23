/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:56:48 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/23 12:23:22 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashtable/ft_hashtable.h"
#include "ft_printf/ft_printf.h"
#include "arrayt/arrayt.h"
#include "../src/hashtable/ft_hashtable_priv.h"

#include <float.h>

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
		ft_hashtable_insert(ht, "bb", AUTOPTR(42));

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
		t_file f = ft_fopen("main.c", O_RDONLY);
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
	// Test arrayt =============================================================
	{
		ARRAYT(int) *array;

		ARRAYT_INIT(array);
		for (size_t i = 0; i < 293; i++)
			ARRAYT_PUSH(array, 0 + i);
		ft_printf("arr len = %lu, should be 293\n", array->length);
		for (size_t i = 0; i < 293; i++)
			if (array->data[i] != (int)i)
			{
				ft_dprintf(2, "Error: arr->data[%lu] should be %d, got %d\n",
					i, (int)i, array->data[i]);
				goto error;
			}
		ARRAYT_REMOVE(array, 200);
		ARRAYT_REMOVE(array, 30000);
		ARRAYT_REMOVE(array, 3);
		for (size_t i = 0; i < array->length; i++)
			ft_printf("arr[%lu] = %d\n", i, array->data[i]);
		while (array->length)
			ARRAYT_REMOVE(array, 0);
		ARRAYT_PUSH(array, 0);
		ARRAYT_PUSH(array, 1);
		ARRAYT_PUSH(array, 2);
		ARRAYT_PUSH(array, 3);
		ARRAYT_PUSH(array, 4);
		ARRAYT_PUSH(array, 5);
		ARRAYT_PUSH(array, 7);
		ARRAYT_PUSH(array, 8);
		ARRAYT_PUSH(array, 9);
		ARRAYT_PUSH(array, 10);
		ARRAYT_INSERT(array, 6, 6);
		for (size_t i = 0; i < array->length; i++)
			ft_printf("arr[%lu] = %d\n", i, array->data[i]);
	error:
		ARRAYT_DESTROY(array);
	}
	// Test arrayt with destroy func ===========================================
	{
		ARRAYT(t_string *) *array;

		ARRAYT_INIT(array);

		ARRAYT_PUSH(array, ft_string_new("Batata 0"));
		ARRAYT_PUSH(array, ft_string_new("Batata 1"));
		ARRAYT_PUSH(array, ft_string_new("Batata 2"));
		ARRAYT_PUSH(array, ft_string_new("Batata 3"));
		ARRAYT_PUSH(array, ft_string_new("Batata 4"));

		for (size_t i = 0; i < array->length; i++)
			ft_printf("arr[%lu] = '%s'\n", i, array->data[i]->data);

		ARRAYT_DESTROY_WITH_FUNC(array, &ft_string_destroy);
	}
	return (0);
}
