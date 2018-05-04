/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:02:43 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/04 16:17:12 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <time.h>
#include <unistd.h>

static void		st_printperm(t_lsfile *file)
{
	ft_putchar(file->is_dir);
	ft_putchar(file->rusr);
	ft_putchar(file->wusr);
	ft_putchar(file->xusr);
	ft_putchar(file->rgrp);
	ft_putchar(file->wgrp);
	ft_putchar(file->xgrp);
	ft_putchar(file->roth);
	ft_putchar(file->woth);
	ft_putchar(file->xoth);
}

static void		st_printlinks(t_lsfile *file)
{
	if (file->links > 99)
		ft_putnbr(file->links);
	else if (file->links > 9)
	{
		ft_putchar(' ');
		ft_putnbr(file->links);
	}
	else
	{
		ft_putstr("  ");
		ft_putnbr(file->links);
	}
}

static void		st_printtimemod(t_lsfile *file)
{
	char			*tmp;

	tmp = ctime(&(file->mtime));
	write(1, (tmp + 4), 12);
}

static void		st_printnode(t_lsfile *file)
{
	if (g_flags & LONG_FORM_FLAG)
	{
		st_printperm(file);
		TAB;
		st_printlinks(file);
		TAB;
		ft_putstr(file->usr_id);
		TAB;
		ft_putstr(file->grp_id);
		TAB;
		ft_putnbr((int)file->bytes);
		TAB;
		st_printtimemod(file);
		TAB;
	}
	ft_putstr(file->name);
	NEWLINE;
}

void			ls_printdir(t_list *files)
{
	t_list			*tmp;

	if (!files)
		return ;
	tmp = files;
	st_printnode(tmp->content);
	while ((tmp = tmp->next))
		st_printnode(tmp->content);
}
