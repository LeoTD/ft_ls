/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:24:27 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/12 19:45:36 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int				prep_format(t_format_vars *v, t_list *f)
{
	t_list		*tmp;
	int			cmp;

	tmp = f;
	while (tmp = tmp->next)
	{
		cmp = ft_numlen(tmp->content->links);
		if (v->links_max_len < cmp)
			v->links_max_len = cmp;
		cmp = ft_strlen(tmp->content->usr_id);
		if (v->usrid_max_len < cmp)
			v->usrid_max_len = cmp;
		cmp = ft_strlen(tmp->content->grp_id);
		if (v->grpid_max_len < cmp)
			v->grpid_max_len = cmp;
		cmp = ft_numlen(tmp->content->bytes);
		if (v->bytes_max_len < cmp)
			v->bytes_max_len = cmp;
	}
}
