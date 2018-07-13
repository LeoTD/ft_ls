/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:14:03 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/12 23:19:56 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		st_assign_flags(char *arg)
{
	int		i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == 'R')
			g_flags |= RECURSIVE_FLAG;
		if (arg[i] == 'l')
			g_flags |= LONG_FORM_FLAG;
		if (arg[i] == 'a')
			g_flags |= INCLUDE_DOT_FLAG;
		if (arg[i] == 't')
			g_flags |= MOD_TIME_SORT_FLAG;
		if (arg[i] == 'r')
			g_flags |= REVERSE_SORT_FLAG;
		if (arg[i] == 'G')
			g_flags |= COLOR_FLAG;
	}
}

void		parse_flags(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
		if (av[i][0] == '-')
			st_assign_flags(av[i]);
}
