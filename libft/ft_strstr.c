/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 12:51:52 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/29 15:44:55 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (haystack[j] != '\0')
	{
		i = 0;
		while (needle[i] == haystack[j])
		{
			i++;
			j++;
			if (needle[i] == '\0')
				return ((char *)haystack + (j - i));
			if (haystack[j] == '\0')
				return (NULL);
		}
		j = j - i + 1;
	}
	return (NULL);
}
