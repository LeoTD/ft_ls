/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:43:39 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/03 22:10:48 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** cmp_ functions return 1 or 0.
** [ 1 ] if 'a' takes precedence.
** [ 0 ] if 'b'.
*/

t_lscmp		g_sort_funks[16] = 
{
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_time_mod_sort,
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_r_lex_sort,
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_r_time_mod_sort,
	&cmp_lex_sort,
	&cmp_lex_sort,
	&cmp_lex_sort
};

int		cmp_lex_sort(void *a, void *b)
{
	if (ft_strcmp(((t_lsfile *)a)->name, ((t_lsfile *)b)->name) < 0)
		return (1);
	return (0);
}

int		cmp_r_lex_sort(void *a, void *b)
{	
	if (ft_strcmp(((t_lsfile *)a)->name, ((t_lsfile *)b)->name) < 0)
		return (0);
	return (1);
}

int		cmp_time_mod_sort(void *a, void *b)
{
	if (((t_lsfile *)a)->mtime < ((t_lsfile *)b)->mtime)
		return (0);
	return (1);
}

int		cmp_r_time_mod_sort(void *a, void *b)
{
	if (((t_lsfile *)a)->mtime < ((t_lsfile *)b)->mtime)
		return (1);
	return (0);
}
