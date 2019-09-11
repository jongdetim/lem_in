/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 12:34:31 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/29 17:17:25 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspace(char c)
{
	if (c == ' ' || c == ',' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	while (ft_iswspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_memset((char*)malloc(1 * sizeof(char)), 0, 1));
	start = i;
	i = ft_strlen(s) - 1;
	while (ft_iswspace(s[i]))
		i--;
	end = i;
	return (ft_strsub(s, start, (size_t)(end - start + 1)));
}
