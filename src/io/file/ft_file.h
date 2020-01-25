/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:18:56 by pqueiroz          #+#    #+#             */
/*   Updated: 2020/01/24 20:58:56 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include <stdlib.h>
# include "../../libft.h"

/*
** File type ===================================================================
*/

typedef struct		s_file
{
	const char		*path;
	int				fd;
	int				mode;
}					t_file;

ssize_t				ft_fwrite(t_file file, t_string *str);
t_file				ft_fopen(const char *path, int mode);
t_string			*ft_fread(t_file file);
void				ft_fclose(t_file file);

#endif
