/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:14:03 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/03 20:00:38 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		parse_flags(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			while (av[i][++j])
			{
				if (av[i][j] == 'R')
					g_flags |= RECURSIVE_FLAG;
				if (av[i][j] == 'l')
					g_flags |= LONG_FORM_FLAG;
				if (av[i][j] == 'a')
					g_flags |= INCLUDE_DOT_FLAG;
				if (av[i][j] == 't')
					g_flags |= MOD_TIME_SORT_FLAG;
				if (av[i][j] == 'r')
					g_flags |= REVERSE_SORT_FLAG;
			}
			j = -1;
		}
	}
}
