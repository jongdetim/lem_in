/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putllnbr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:08:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:08:58 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putllnbr(long long n)
{
	long long	res;
	long long	m;

	m = n;
	if (m < 0)
	{
		m = m * -1;
		write(1, "-", 1);
	}
	res = m % 10 + '0';
	if ((m / 10) != 0)
		ft_putllnbr(m / 10);
	write(1, &res, 1);
}
