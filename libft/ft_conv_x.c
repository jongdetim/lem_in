/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 16:39:03 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:19:13 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			conv_x(t_printf *data)
{
	unsigned long long	d;
	int					len;
	short				hash;

	hash = 0;
	d = va_arg(data->args, unsigned long long);
	d = typecast_u(data, d);
	if (data->hash == 1 && d != 0)
		hash = 2;
	len = ft_digcountbase_u(d, 16);
	flaghandler_x(data, len, hash, d);
}
