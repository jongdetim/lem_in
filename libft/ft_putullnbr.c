/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putullnbr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:09:19 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:09:27 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putullnbr(unsigned long long n)
{
	unsigned long long	res;
	unsigned long long	m;

	m = n;
	res = m % 10 + '0';
	if ((m / 10) != 0)
		ft_putllnbr(m / 10);
	write(1, &res, 1);
}
