/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:05:30 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/29 18:07:39 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			res;
	long int	m;

	m = n;
	if (m < 0)
	{
		m = m * -1;
		write(fd, "-", 1);
	}
	res = m % 10 + '0';
	if ((m / 10) != 0)
		ft_putnbr_fd(m / 10, fd);
	write(fd, &res, 1);
}
