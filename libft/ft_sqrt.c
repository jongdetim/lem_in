/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 16:05:49 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/06 16:06:00 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_sqrt(unsigned int num)
{
	unsigned int res;

	res = 0;
	while (res * res < num)
	{
		res++;
	}
	return (res);
}
