/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoabase.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:26:22 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:26:24 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_transferbase(unsigned long long n, int i, int base)
{
	int	j;

	j = 0;
	while (j < i)
	{
		n = (n / base);
		j++;
	}
	while (j >= 0)
	{
		n = n % base;
		j--;
	}
	return (n);
}

char		*ft_itoabase(unsigned long long n, int base)
{
	int		digcount;
	char	*str;
	int		i;
	int		temp;

	i = 0;
	digcount = ft_digcountbase_u(n, base);
	str = (char*)malloc(sizeof(char) * (digcount + 1));
	if (!str)
		return (NULL);
	while (i < (digcount))
	{
		temp = ft_transferbase(n, digcount - (i) - 1, base);
		str[i] = temp <= 9 ? temp + '0' : temp - 10 + 'a';
		i++;
	}
	str[i] = '\0';
	return (str);
}
