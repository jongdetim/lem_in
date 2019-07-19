/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 17:55:28 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/28 18:31:27 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (*s2 != '\0' && j < n)
	{
		s1[i] = *s2;
		i++;
		s2++;
		j++;
	}
	s1[i] = '\0';
	return ((char*)s1);
}
