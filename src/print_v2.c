/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:24:27 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/12 23:25:43 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>

void			printfname(t_lsfile *f)
{
	if (g_flags & COLOR_FLAG)
	{
		if (f->is_dir == 'd')
			ft_putstr("\033[1;96m");
		else if (f->xusr == 'x' || f->xgrp == 'x' || f->xoth == 'x')
			ft_putstr("\033[51;31m");
	}
	ft_putstr(f->name);
	ft_putstr("\033[0m");
}

int				prep_format(t_format_vars *v, t_list *f)
{
	t_list			*tmp;
	size_t			cmp;

	tmp = f;
	while (tmp)
	{
		cmp = ft_numlen(((t_lsfile *)(tmp->content))->links);
		if (v->links_max_len < cmp)
			v->links_max_len = cmp;
		cmp = ft_strlen(((t_lsfile *)(tmp->content))->usr_id);
		if (v->usrid_max_len < cmp)
			v->usrid_max_len = cmp;
		cmp = ft_strlen(((t_lsfile *)(tmp->content))->grp_id);
		if (v->grpid_max_len < cmp)
			v->grpid_max_len = cmp;
		cmp = ft_numlen(((t_lsfile *)(tmp->content))->bytes);
		if (v->bytes_max_len < cmp)
			v->bytes_max_len = cmp;
		tmp = tmp->next;
	}
	return (0);
}

int				ls_print_with_padding(int max, int left, char *str)
{
	int				strlen;
	char			buf[256];
	int				i;

	i = -1;
	if (max > 255)
		max = 255;
	ft_bzero(buf, 256);
	strlen = ft_strlen(str);
	if (left == 1)
	{
		while (++i < max - strlen)
			buf[i] = ' ';
		strncat(buf, str, max + 1);
	}
	else if (left == 0)
	{
		strncpy(buf, str, strlen);
		i += strlen;
		while (++i < max)
			buf[i] = ' ';
	}
	ft_putstr(buf);
	return (0);
}

void			ls_printdir(t_list *files)
{
	t_list			*tmp;
	t_format_vars	v;

	if (!files)
		return ;
	v.links_max_len = 0;
	v.usrid_max_len = 0;
	v.grpid_max_len = 0;
	v.bytes_max_len = 0;
	prep_format(&v, files);
	tmp = files;
	ls_printnode(&v, tmp->content);
	while ((tmp = tmp->next))
		ls_printnode(&v, tmp->content);
}
