/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:46:48 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/13 00:36:07 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

static void		st_fillnode(struct stat *statbuf, t_lsfile *tmp)
{
	int				i;

	tmp->bytes = statbuf->st_size;
	tmp->links = statbuf->st_nlink;
	tmp->inode = statbuf->st_ino;
	tmp->is_dir = (S_ISDIR(statbuf->st_mode)) ? 'd' : '-';
	tmp->is_dir = (S_ISLNK(statbuf->st_mode)) ? 'l' : tmp->is_dir;
	tmp->rusr = (statbuf->st_mode & S_IRUSR) ? 'r' : '-';
	tmp->wusr = (statbuf->st_mode & S_IWUSR) ? 'w' : '-';
	tmp->xusr = (statbuf->st_mode & S_IXUSR) ? 'x' : '-';
	tmp->rgrp = (statbuf->st_mode & S_IRGRP) ? 'r' : '-';
	tmp->wgrp = (statbuf->st_mode & S_IWGRP) ? 'w' : '-';
	tmp->xgrp = (statbuf->st_mode & S_IXGRP) ? 'x' : '-';
	tmp->roth = (statbuf->st_mode & S_IROTH) ? 'r' : '-';
	tmp->woth = (statbuf->st_mode & S_IWOTH) ? 'w' : '-';
	tmp->xoth = (statbuf->st_mode & S_IXOTH) ? 'x' : '-';
	tmp->is_link = (S_ISLNK(statbuf->st_mode)) ? '@' : ' ';
	tmp->atime = statbuf->st_atime;
	tmp->mtime = statbuf->st_mtime;
	tmp->ctime = statbuf->st_ctime;
	i = readlink(tmp->name, tmp->sym_path, 1023);
	tmp->sym_path[i] = '\0';
	tmp->is_sticky = (statbuf->st_mode & S_ISVTX) ? 1 : 0;
	tmp->is_setuid = (statbuf->st_mode & S_ISUID) ? 1 : 0;
	tmp->is_setgid = (statbuf->st_mode & S_ISGID) ? 1 : 0;
}

t_lsfile		*ls_newnode(struct stat *statbuf, char *name)
{
	t_lsfile		*tmp;
	struct passwd	*pwd;
	struct group	*grp;

	MEM_CHECK(tmp = malloc(sizeof(*tmp)));
	MEM_CHECK(tmp->name = ft_strdup(name));
	st_fillnode(statbuf, tmp);
	if ((pwd = getpwuid(statbuf->st_uid)) != NULL)
	{
		MEM_CHECK(tmp->usr_id = ft_strdup(pwd->pw_name));
	}
	else
	{
		MEM_CHECK(tmp->usr_id = ft_strnew(0));
	}
	if ((grp = getgrgid(statbuf->st_gid)) != NULL)
	{
		MEM_CHECK(tmp->grp_id = ft_strdup(grp->gr_name));
	}
	else
	{
		MEM_CHECK(tmp->grp_id = ft_strnew(0));
	}
	return (tmp);
}

void			ls_addnode(t_list **h, struct stat *statbuf, char *name)
{
	t_list			*tmp;
	t_list			*res;
	t_lsfile		*content;

	MEM_CHECK(content = ls_newnode(statbuf, name));
	MEM_CHECK(res = ft_lstnew(content, sizeof(*content)));
	free(content);
	if (*h == 0)
		*h = res;
	else if ((*h)->next)
	{
		tmp = (*h)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = res;
	}
	else
		(*h)->next = res;
}

void			ls_clrnode(void *content, size_t csize)
{
	t_lsfile		*tmp;

	tmp = NULL;
	if (csize || !csize)
		tmp = (t_lsfile *)content;
	free(tmp->name);
	free(tmp->usr_id);
	free(tmp->grp_id);
	free(tmp);
}
