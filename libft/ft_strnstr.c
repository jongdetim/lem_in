/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 13:46:39 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/28 18:32:24 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (haystack[j] != '\0' && j < len)
	{
		i = 0;
		while (needle[i] == haystack[j])
		{
			i++;
			j++;
			if (needle[i] == '\0')
				return ((char *)haystack + (j - i));
			if (j >= len || haystack[j] == '\0')
				return (NULL);
			if (needle[i] != haystack[j])
				j = j - i;
		}
		j++;
	}
	return (NULL);
}
