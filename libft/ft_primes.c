/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_primes.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 18:38:10 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 18:39:57 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int			ft_get_next_prime(int n)
{
	while (n % 2 == 0)
		n++;
	while (!ft_isprime(n))
		n++;
	return (n);
}
