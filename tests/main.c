/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:56:48 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/24 23:53:58 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_file		*f;
	t_string	*tmp;

	/* test t_file */
	f = ft_fopen("test.txt", O_RDWR);
	if (f->fd > -1)
		ft_putendl("ft_fopen OK");
	else
		ft_putendl("ft_fopen FAIL");
	tmp = ft_fread(f);
	ft_putendl("ft_fread ===========");
	ft_putstr(tmp->data);
	// It works
	// ft_putendl("ft_fwrite ==========");
	// tmp->append(tmp, "BLAH BLAH BLAH\n");
	// if (ft_fwrite(f, tmp) > 0)
	// 	ft_putendl("File written OK");
	// else
	// 	ft_putendl("File written FAIL");
	// ft_putendl("ft_fread end =======");
	ft_string_destroy(&tmp);
	ft_fdestroy(f);

	int *a = AUTOPTR(20);
	ft_putendl("AUTOPTR (int 20) ===");
	ft_putnbr(*a);
	ft_putchar('\n');
	ft_putendl("AUTOPTR ============");
	free(a);

	/* test ft_strdupchr */
	char *s;

	s = ft_strdupchr("batata\npotato", '\n');
	ft_putendl(s);
	ft_strdel(&s);

	ft_putendl("t_string ===========");
	t_string *string = ft_string_new("test");
	ft_putendl(string->data);
	ft_putnbr((int)string->length);
	ft_putchar('\n');
	string->append(string, " another test");
	ft_putendl(string->data);
	ft_putnbr((int)string->length);
	ft_putchar('\n');
	string->destroy(&string);
	ft_putendl("t_string end =======");

	t_array *arr = ft_array_new();
	ft_array_push(arr, AUTOPTR(42));
	ft_array_push(arr, AUTOPTR(17));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));
	ft_array_push(arr, AUTOPTR(255));

	ft_array_delete(arr, 1);
	ft_array_delete(arr, 1);

	ft_putstr("Arr size ");
	ft_putnbr((int) arr->size);
	ft_putchar('\n');

	for (size_t i = 0; i < arr->length; i++)
	{
		ft_putnbr(*((int *)arr->data[i]));
		ft_putchar('\n');
	}
	ft_array_terminate(&arr);

	t_string *ss = ft_string_new("is good!");
	ft_string_prepend(ss, "Batata ");
	ft_putendl(ss->data);

	ft_string_remove(ss, 7, 2);
	ft_string_inpend(ss, 7, "are");
	ft_putendl(ss->data);

	ft_string_remove(ss, 0, 200);
	ft_putendl(ss->data);

	ft_string_destroy(&ss);

	// t_bignum *n = ft_bignum(NULL, 10);
	// ft_bignum_add(n, 10);
	// ft_bignum_add(n, 100);
	// ft_bignum_add(n, 1000);
	// ft_bignum_add(n, 42);
	// printf("'%s'\n", n->str);
	return (0);
}
