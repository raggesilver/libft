/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:17:03 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/15 13:23:08 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

# define _IW2(x)			(x == '\r' || x == '\v' || x == '\f')
# define IS_WHITESPACE(x)	(x == ' ' || x == '\t' || x == '\n' || _IW2(x))

# define CONTINUE_IF(cond)				({ if (cond) continue ; })
# define RETURN_IF(cond)				({ if (cond) return ; })
# define RETURN_VAL_IF(val, cond)		({ if (cond) return (val); })

# define CONTINUE_IF_FAIL(cond)			({ if (!cond) continue ; })
# define RETURN_IF_FAIL(cond)			({ if (!cond) return ; })
# define RETURN_VAL_IF_FAIL(val, cond)	({ if (!cond) return (val); })

# define MIN(x, y)	((x > y) ? y : x)
# define MAX(x, y)	((x > y) ? x : y)
# define MOD(x)		((x < 0) ? -x : x)

# define BUFF_SIZE	32

#endif
