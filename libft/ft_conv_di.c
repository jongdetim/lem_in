/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_di.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 20:19:14 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/01 16:59:37 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	typecast_di(t_printf *data, long long d)
{
	if (data->length == 'l')
		d = (long)d;
	if (data->length == '0')
		d = (int)d;
	if (data->length == 'c')
		d = (char)d;
	if (data->length == 'h')
		d = (short)d;
	return (d);
}

static void			flaghandler2_d(t_printf *data, short extra,
											short len, short min)
{
	short	i;

	i = 0;
	if (min == 1)
	{
		write(1, "-", 1);
		data->width--;
		data->ret++;
	}
	while (i < extra)
	{
		write(1, "0", 1);
		i++;
		data->ret++;
	}
	i = 0;
	while (data->width > i + len + extra &&
		data->zero == 1 && data->minus == 0 && data->dot == 0)
	{
		write(1, "0", 1);
		i++;
		data->ret++;
	}
}

static short		flaghandler_d(t_printf *data, short min, int len)
{
	short		extra;
	short		i;

	i = 0;
	extra = 0;
	if (data->precision > len)
		extra = data->precision - len;
	if (min == 1 && data->plus == 1 && data->minus == 0 &&
								data->width > data->precision)
		i--;
	while (data->width > i + len + extra + min + data->plus &&
		data->minus == 0 && (data->zero == 0 || data->dot == 1))
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	if (data->plus == 1 && min == 0)
	{
		write(1, "+", 1);
		data->ret++;
		data->width--;
	}
	return (extra);
}

static void			flaghandler3_d(t_printf *data,
									short extra, long long d)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digcountbase(d, 10);
	if (data->precision == 0 && data->dot == 1 && d == 0)
	{
		if (data->width != 0)
			write(1, " ", 1);
		else
			data->ret--;
	}
	else
	{
		ft_putllnbr(d);
		if (d == 922337203685477580)
			lowestll(data);
	}
	data->ret += len;
	while (data->width > i + len + extra && data->minus == 1)
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
}

void				conv_d(t_printf *data)
{
	long long	d;
	short		min;
	int			len;
	short		extra;

	min = 0;
	d = va_arg(data->args, long long);
	d = typecast_di(data, d);
	if (d < 0)
	{
		if (d < -9223372036854775807)
			d /= 10;
		min = 1;
		d *= -1;
	}
	len = ft_digcountbase(d, 10);
	if (data->space == 1 && data->plus == 0 && min == 0)
	{
		write(1, " ", 1);
		data->width--;
		data->ret++;
	}
	extra = flaghandler_d(data, min, len);
	flaghandler2_d(data, extra, len, min);
	flaghandler3_d(data, extra, d);
}
