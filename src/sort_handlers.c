/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:40:51 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/03 21:33:42 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int		st_set_funk_id(void)
{
	int		res;

	res = 0;
	if (g_flags & MOD_TIME_SORT_FLAG)
		res |= MOD_TIME_SORT_FLAG;
	if (g_flags & REVERSE_SORT_FLAG)
		res |= REVERSE_SORT_FLAG;
	return (res);
}

void		ls_dirsort(t_list **files)
{
	int		funk_id;

	funk_id = st_set_funk_id();
	ft_lstsort(files, g_sort_funks[funk_id]);
}
