/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 15:32:34 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:46:14 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	typecast_u(t_printf *data, unsigned long long d)
{
	if (data->length == 'l')
		d = (unsigned long)d;
	if (data->length == '0')
		d = (unsigned int)d;
	if (data->length == 'c')
		d = (unsigned char)d;
	if (data->length == 'h')
		d = (unsigned short)d;
	return (d);
}

static	void		flaghandler2_u(t_printf *data, short extra, short len)
{
	short	i;

	i = 0;
	while (i < extra)
	{
		write(1, "0", 1);
		i++;
		data->ret++;
	}
	i = 0;
	while (data->width > i + len + extra && data->zero == 1 &&
									data->minus == 0 && data->dot == 0)
	{
		write(1, "0", 1);
		i++;
		data->ret++;
	}
}

static short		flaghandler_u(t_printf *data, int len)
{
	short		extra;
	short		i;

	i = 0;
	extra = 0;
	if (data->precision > len)
		extra = data->precision - len;
	while (data->width > i + len + extra && data->minus == 0 &&
									(data->zero == 0 || data->dot == 1))
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	flaghandler2_u(data, extra, len);
	return (extra);
}

void				conv_u(t_printf *data)
{
	unsigned long long	d;
	int					len;
	short				i;
	short				extra;

	i = 0;
	d = typecast_u(data, va_arg(data->args, unsigned long long));
	len = ft_digcountbase_u(d, 10);
	extra = flaghandler_u(data, len);
	if (data->precision == 0 && data->dot == 1 && d == 0)
	{
		if (data->width != 0)
			write(1, " ", 1);
		else
			data->ret--;
	}
	else
		ft_putullnbr(d);
	data->ret += len;
	while (data->width > i + len + extra && data->minus == 1)
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
}
