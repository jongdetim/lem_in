/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 16:06:30 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/06 16:06:38 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_power(int num, int power)
{
	int i;

	i = 1;
	while (i < power)
	{
		num *= num;
		i++;
	}
	return (num);
}
