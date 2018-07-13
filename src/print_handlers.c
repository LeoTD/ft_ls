/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:02:43 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/12 23:29:01 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

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
	ft_putchar(file->is_link);
}

static void		st_printlinks(t_format_vars *v, t_lsfile *file)
{
	char			*tmp;

	tmp = ft_itoa(file->links);
	ls_print_with_padding(v->links_max_len, 1, tmp);
	free(tmp);
}

static void		st_printtimemod(t_lsfile *file)
{
	char			*tmp;

	tmp = ctime(&(file->mtime));
	write(1, (tmp + 4), 12);
}

static void		st_printbytes(t_format_vars *v, t_lsfile *file)
{
	char			*tmp;

	tmp = ft_itoa(file->bytes);
	ls_print_with_padding(v->bytes_max_len, 1, tmp);
	free(tmp);
}

void		ls_printnode(t_format_vars *v, t_lsfile *file)
{
	if (g_flags & LONG_FORM_FLAG)
	{
		st_printperm(file);
		SPACE;
		st_printlinks(v, file);
		SPACE;
		ls_print_with_padding(v->usrid_max_len, 0, file->usr_id);
		SPACE;
		ls_print_with_padding(v->grpid_max_len, 0, file->grp_id);
		SPACE;
		st_printbytes(v, file);
		SPACE;
		st_printtimemod(file);
		SPACE;
	}
	printfname(file);
	NEWLINE;
}
