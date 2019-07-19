/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 15:38:58 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/27 15:52:51 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	fresh = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (s && f && fresh)
	{
		while (s[i] != '\0')
		{
			fresh[i] = f(((char*)s)[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
