/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:46:42 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/14 15:07:06 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	ptr = ft_strnstr(largestring, smallstring, 5);

	printf("The substring is: %s\n", ptr ?: "Not found");
	return (0);
}
