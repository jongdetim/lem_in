/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 16:17:52 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/27 16:33:35 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 != s2)
	{
		i = 0;
		while ((s1[i] || s2[i]) && i < n)
		{
			if (s2[i] == '\0' || s1[i] == '\0' || s1[i] - s2[i] != 0)
				return (0);
			else
				i++;
		}
	}
	return (1);
}
