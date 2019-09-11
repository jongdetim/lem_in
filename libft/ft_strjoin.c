/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:29:45 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/03 21:00:56 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*fresh;
	int		i;
	int		j;

	fresh = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		fresh[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		fresh[i] = s2[j];
		i++;
		j++;
	}
	fresh[i] = '\0';
	free(s1);
	free(s2);
	return (fresh);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;
	int		j;

	fresh = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (fresh)
	{
		while (s1[i] != '\0')
		{
			fresh[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			fresh[i] = s2[j];
			i++;
			j++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
