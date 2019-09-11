/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digcountbase.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:26:02 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:26:06 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digcountbase_u(unsigned long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

int		ft_digcountbase(long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}
