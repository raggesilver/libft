/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:46:42 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/02/14 21:38:28 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char string1[60] = "Taj Mahal is a historic monument in India.";

int	main(int argc, char **argv)
{
	char *s1 = ft_strdup("batata");
	char *s2 = ft_strdup(argv[argc - 1]);
	printf("'%s' is%s equal to '%s'\n", s1, (ft_strncmp(s1, s2, 6)) ? " not" : "", s2);
	return (0);
}
