/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_o.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 16:29:20 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:21:26 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			conv_o(t_printf *data)
{
	unsigned long long	d;
	int					len;
	short				hash;

	hash = 0;
	d = va_arg(data->args, unsigned long long);
	d = typecast_u(data, d);
	if (data->hash == 1 && d != 0)
		hash = 1;
	len = ft_digcountbase_u(d, 8);
	flaghandler_o(data, len, hash, d);
}
