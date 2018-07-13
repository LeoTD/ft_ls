/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:12:20 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/12 23:21:34 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define MEM_CHECK(x) if (!(x)) exit(1)

# define PF(x) printf(x)
# define SPACE ft_putchar(' ')
# define TAB ft_putchar('\t')
# define NEWLINE ft_putchar('\n')

# define MAX_FILENAME 255
# define MAX_PATHNAME 4096

# define LS_IS_DIR(x) ((x)->content->is_dir == 'd')
# define FNAME(x) ((x)->(t_lsfile *)content->name)

# include <time.h>
# include "libft.h"
# include <sys/stat.h>

# define LEX_SORT 0
# define R_LEX_SORT 8
# define TIME_MOD_SORT 4
# define R_TIME_MOD_SORT 12

typedef enum				e_lsflags
{
	LONG_FORM_FLAG = 1,
	RECURSIVE_FLAG = 2,
	MOD_TIME_SORT_FLAG = 4,
	REVERSE_SORT_FLAG = 8,
	INCLUDE_DOT_FLAG = 16,
	COLOR_FLAG = 32
}							t_lsflags;

int							g_flags;

typedef struct				s_lsfile
{
	char					*name;
	long long				bytes;
	int						links;
	unsigned long long		inode;
	char					is_link;
	char					is_dir;
	char					rusr;
	char					wusr;
	char					xusr;
	char					rgrp;
	char					wgrp;
	char					xgrp;
	char					roth;
	char					woth;
	char					xoth;
	time_t					atime;
	time_t					mtime;
	time_t					ctime;
	char					*usr_id;
	char					*grp_id;
}							t_lsfile;

typedef struct				s_format_vars
{
	size_t					links_max_len;
	size_t					usrid_max_len;
	size_t					grpid_max_len;
	size_t					bytes_max_len;
}							t_format_vars;

void						ft_ls(char *dir, char *path);
void						ls_addnode(t_list **h, struct stat *s, char *name);
void						ls_printdir(t_list *files);
void						ls_printnode(t_format_vars *v, t_lsfile *file);
int							ls_print_with_padding(int max, int left, char *str);
void						printfname(t_lsfile *f);
void						parse_flags(int ac, char **av);
void						ls_dirsort(t_list **files);
void						ls_clrnode(void *content, size_t csize);

int							prep_format(t_format_vars *v, t_list *f);
int							print_with_padding(int max, int left, char *str);

int							cmp_lex_sort(void *a, void *b);
int							cmp_r_lex_sort(void *a, void *b);
int							cmp_time_mod_sort(void *a, void *b);
int							cmp_r_time_mod_sort(void *a, void *b);

typedef int					(*t_lscmp)(void *, void *);

t_lscmp						g_sort_funks[16];

#endif
