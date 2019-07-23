/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 13:36:22 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/23 15:30:02 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			ft_isprime(int n)
{
	int i;

	i = 2;
	if (n == 1 || n == 0)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int			get_next_prime(int n)
{
	while (n % 2 == 0)
		n++;
	while (!ft_isprime(n))
		n++;
	return (n);
}

int			ft_hash(char *key, int size)
{
	int index;
	int i;

	i = 0;
	index = 0;
	if (key == NULL)
		return (-1);
	while (key[i] != '\0')
	{
		index = index + key[i] * (i + 1);
		i++;
	}
	index = ft_abs(index);
	return (index % size);
}
