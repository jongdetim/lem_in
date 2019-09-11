/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 15:47:33 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/27 15:52:52 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	fresh = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (s && f && fresh)
	{
		while (s[i] != '\0')
		{
			fresh[i] = f(i, ((char*)s)[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
