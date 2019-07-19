/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pythagoras.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 16:59:24 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/06 17:00:19 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_pythagoras(int x, int y)
{
	return (ft_sqrt(ft_power(x, 2) + ft_power(y, 2)));
}
