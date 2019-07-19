/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:57:13 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/25 17:15:42 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	x;
	char	*ptr;

	ptr = NULL;
	x = c;
	if (c != 0)
	{
		while (*s != '\0')
		{
			if (*s == x)
				ptr = (char*)s;
			s++;
		}
		return (ptr);
	}
	else
	{
		while (*s != '\0')
			s++;
		return ((char*)s);
	}
}
