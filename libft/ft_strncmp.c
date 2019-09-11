/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:18:11 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/29 16:16:46 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (index == n)
			return (0);
		if (s2[index] == '\0')
			return (1);
		if (s1[index] == '\0')
			return (-1);
		if (((unsigned char)s1[index] - (unsigned char)s2[index]) != 0)
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		else
			index++;
	}
	return (0);
}
