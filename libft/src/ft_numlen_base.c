/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 04:11:28 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/11 19:40:39 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen_base(long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0 && base == 10)
		i++;
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}
