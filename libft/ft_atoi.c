/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 13:18:18 by tide-jon       #+#    #+#                */
/*   Updated: 2019/04/01 15:06:14 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	result = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		if ((result * 10 + *str - '0') < result && sign == 1)
			return (-1);
		if ((result * 10 + *str - '0') < result && sign == -1)
			return (0);
		result = (result * 10) + (*str - '0');
		str++;
		if (result > 9223372036854775807u && sign == 1)
			return (-1);
		if (result > 9223372036854775808u && sign == -1)
			return (0);
	}
	return ((long long)result * sign);
}
