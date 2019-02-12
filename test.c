/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:46:42 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/12 12:50:12 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main()
{
	char *a = ft_strdup("batata");
	char *b = malloc(13);
	b = ft_strcpy(b, "BatatA");
	b = ft_strncat(b, a, 5);
	printf("String: %s\n", b);
	return (0);
}
