/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:56:48 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/06 15:51:08 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(void)
{
	t_file	*f;
	char	*tmp;

	/* test t_file */
	f = ft_fopen("main.c", O_RDONLY);
	if (f->fd > -1)
		ft_putendl("ft_fopen OK");
	else
		ft_putendl("ft_fopen FAIL");
	tmp = ft_fread(f);
	ft_putendl("ft_fread ========");
	ft_putstr(tmp);
	ft_putendl("ft_fread end ====");
	ft_strdel(&tmp);
	ft_fdestroy(f);

	/* test ft_strdupchr */
	char *s;

	s = ft_strdupchr("batata\npotato", '\n');
	ft_putendl(s);
	ft_strdel(&s);
	return (0);
}
