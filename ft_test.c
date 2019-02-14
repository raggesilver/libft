/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:46:42 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/13 16:18:01 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	str1[15];
	char	str2[15];
	int		ret;

	ft_memcpy(str1, "abcdef", 6);
	ft_memcpy(str2, "ABCDEF", 6);
	ret = ft_memcmp(str1, str2, 5);
	if (ret > 0)
		printf("str2 is less than str1");
	else if (ret < 0)
		printf("str1 is less than str2");
	else
		printf("str1 is equal to str2");
	return (0);
}
