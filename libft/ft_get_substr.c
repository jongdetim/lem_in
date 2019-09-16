/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_substr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 19:09:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 19:09:45 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_first_substr(char *str)
{
	int i;
	int start;

	i = 0;
	while (str[i] != '\0' && ft_iswhitespace(str[i]) == 1)
		i++;
	start = i;
	while (str[i] != '\0' && ft_iswhitespace(str[i]) != 1)
		i++;
	return (ft_strsub(str, start, i - start));
}
