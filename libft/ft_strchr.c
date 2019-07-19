/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:25:31 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/25 17:14:29 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;

	x = c;
	if (c != 0)
	{
		while (*s != '\0')
		{
			if (*s == x)
				return ((char*)s);
			s++;
		}
		return (NULL);
	}
	else
	{
		while (*s != '\0')
			s++;
		return ((char*)s);
	}
}
