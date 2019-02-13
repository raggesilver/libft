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

char *msg = "This is the string: not copied";

int	main()
{
	char buffer[80];
	ft_memset(buffer, '\0', 80);
	ft_memccpy(buffer, msg, ':', 80);
	printf("%s\n", buffer);
	return (0);
}
