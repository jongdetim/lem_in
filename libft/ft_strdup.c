/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 13:14:48 by tide-jon       #+#    #+#                */
/*   Updated: 2019/04/03 14:23:08 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, s1));
}
