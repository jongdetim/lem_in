/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:48:50 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/25 12:08:38 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (j < len)
	{
		while ((src[i] != '\0') && j < len)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		if (j < len)
		{
			dst[j] = '\0';
			j++;
		}
	}
	return (dst);
}
