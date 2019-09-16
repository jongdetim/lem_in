/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 18:38:50 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 18:39:48 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_hash_str(char *key, int size)
{
	int index;
	int i;
	int key_len;

	i = 0;
	index = 0;
	if (key == NULL)
		return (-1);
	key_len = ft_strlen(key);
	while (key[i] != '\0')
	{
		index = (index) + (key[key_len - i - 1]) *
					((32 ^ i) + (index) * (i ^ 7));
		i++;
	}
	index = ft_abs(index);
	return (index % size);
}
