/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 14:54:04 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/18 12:11:24 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_transfer(long long n, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		n = (n / 10);
		j++;
	}
	while (j >= 0)
	{
		n = n % 10;
		j--;
	}
	if (n < 0)
		n = n * -1;
	return (n);
}

char			*ft_itoa(long long n)
{
	int		digcount;
	int		sign;
	char	*str;
	int		i;

	i = 0;
	sign = 0;
	digcount = ft_digcount(n);
	if (n < 0)
		sign = 1;
	str = (char*)malloc(sizeof(char) * (sign + digcount + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	while (i < (digcount + sign))
	{
		str[i] = (ft_transfer(n, digcount - (i - sign) - 1) + '0');
		i++;
	}
	str[i] = '\0';
	return (str);
}
