/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:15:19 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/03 21:02:38 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> //printf
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "libft.h"
#include "ft_ls.h"

void	ft_ls(char *dir, char *path);

static void		st_prep_print_buffer(char *buf, char *path, char *name)
{
	ft_strclr(buf);
	ft_strcat(buf, path);
	ft_strcat(buf, name);
	NEWLINE;
	ft_putstr(buf);
	ft_putstr(":");
	NEWLINE;
	ft_strcat(buf, "/");
}

static void		st_recurse(t_list *files, char *path)
{
	t_list			*tmp;
	t_lsfile		*file;
	char			path_buf[MAX_PATHNAME];

	path_buf[0] = '\0';
	if (!files)
		return ;
	tmp = files;
	file = tmp->content;
	if (file->is_dir == 'd' && ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
	{
		st_prep_print_buffer(path_buf, path, file->name);
		ft_ls(file->name, path_buf);
	}
	while ((tmp = tmp->next))
	{
		file = tmp->content;
		if (file->is_dir == 'd' && ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
		{
			st_prep_print_buffer(path_buf, path, file->name);
			ft_ls(file->name, path_buf);
		}
	}
}

void	ft_ls(char *dir, char *path)
{
	DIR				*dir_ptr;
	struct dirent	*entry;
	struct stat		statbuf;
	t_list			*files;

	if((dir_ptr = opendir(dir)) == NULL)
	{
		ft_putstr_fd("cannot open directory: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd("\n", 2);
		return ;
    }
	files = NULL;
	chdir(dir);
	while((entry = readdir(dir_ptr)) != NULL)
	{
		lstat(entry->d_name, &statbuf);
		if ((g_flags & INCLUDE_DOT_FLAG) || *(entry->d_name) != '.')
			ls_addnode(&files, &statbuf, entry->d_name);
	}
	ls_dirsort(&files);
	ls_printdir(files);
	if (g_flags & RECURSIVE_FLAG)
		st_recurse(files, path);
	chdir("..");
	closedir(dir_ptr); //REMEMBER: Clean up function!
}

int		main(int argc, char **argv)
{
	char			path_buf[MAX_PATHNAME];
	int				i;
	int				done;

	done = 0;
	parse_flags(argc, argv);
	i = 0;
	while (++i < argc)
		if (argv[i][0] != '-')
		{
			done = 1;
			ft_strclr(path_buf);
			ft_strcat(path_buf, argv[i]);
			ft_strcat(path_buf, "/");
			ft_ls(argv[i], path_buf);
		}
	if (!done)
	{
		ft_strclr(path_buf);
		ft_strcat(path_buf, "./");
		ft_ls(".", path_buf);
	}
	return (0);
}
