/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:15:19 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/01 23:11:49 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

static void		st_printdir(char *dir, int depth)
{
	int		i;

	i = -1;
	while (++i < depth)
		ft_putchar(' ');
	ft_putstr(dir);
	ft_putstr("/\n");
}

static void		st_printfile(char *dir, int depth)
{
	int		i;

	i = -1;
	while (++i < depth)
		ft_putchar(' ');
	ft_putstr(dir);
	ft_putstr("\n");
}

void	printdir(char *dir, int depth)
{
	DIR				*dir_ptr;
	struct dirent	*entry;
	struct stat		statbuf;

	if((dir_ptr = opendir(dir)) == NULL)
	{
		ft_putstr_fd("cannot open directory: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd("\n", 2);
		return ;
    }
	chdir(dir);
	while((entry = readdir(dir_ptr)) != NULL)
	{
		lstat(entry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode)) {
			if(ft_strcmp(".", entry->d_name) == 0 || ft_strcmp("..", entry->d_name) == 0)
				continue ;
			st_printdir(entry->d_name, depth);
			printdir(entry->d_name, depth + 4);
		}
		else
			st_printfile(entry->d_name, depth);
	}
	chdir("..");
	closedir(dir_ptr);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printdir(argv[1], 0);
	return (0);
}
