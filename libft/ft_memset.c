/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 14:27:38 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/28 18:28:05 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	n;

	n = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = n;
		i++;
	}
	return (b);
}
