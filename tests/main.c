/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:56:48 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 21:36:12 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashtable/ft_hashtable.h"
#include "ft_printf/ft_printf.h"
#include "../src/hashtable/ft_hashtable_priv.h"

#include <float.h>

int	main(void)
{
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
	ft_printf("Hello world!\n");
	ft_printf("'%d'\n", 42);
	ft_printf("'%x'\n", 42);
	ft_printf("'%X'\n", 42);
	ft_printf("'%o'\n", 42);
	ft_printf("'%i'\n", 42);
	ft_printf("'%f'\n", 42.42f);
	ft_printf("'%Lf'\n", LDBL_MAX);
	// Test t_file =============================================================
	{
		t_file *f = ft_fopen("main.c", O_RDONLY);
		t_string *s = ft_fread(f);
		ft_printf("Read contents from `main.c`\n%s\n", s->data);
		ft_string_destroy(&s);
		ft_fclose(f);
		ft_fdestroy(f);
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
	return (0);
}
