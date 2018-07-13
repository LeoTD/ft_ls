/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:33:26 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/12 22:39:23 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		numlen;
	long	nc;
	char	*str;

	numlen = ft_numlen(n);
	nc = (long)n;
	str = ft_strnew(numlen);
	if (str == NULL)
		return (NULL);
	str[numlen--] = '\0';
	if (nc < 0)
	{
		str[0] = '-';
		nc = -nc;
	}
	str[numlen--] = (nc % 10) + '0';
	while (nc >= 10)
	{
		nc /= 10;
		str[numlen--] = (nc % 10) + '0';
	}
	return (str);
}
