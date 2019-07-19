/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:13:11 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/27 17:23:02 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	substr = (char*)malloc((len + 1) * sizeof(char));
	if (substr && s)
	{
		while (i < len)
		{
			substr[i] = s[start];
			start++;
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
