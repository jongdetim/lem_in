/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_o2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:21:09 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/01 17:21:36 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	flaghandler_o_zero(t_printf *data, short extra,
										short len, short hash)
{
	short i;

	i = 0;
	while (i < extra - hash)
	{
		write(1, "0", 1);
		i++;
		data->ret++;
	}
	i = 0;
	while (data->width > i + len + extra + hash && data->zero == 1 &&
									data->minus == 0 && data->dot == 0)
	{
		write(1, "0", 1);
		i++;
		data->ret++;
	}
	if (hash == 1)
	{
		write(1, "0", 1);
		data->ret++;
	}
}

static void		minus_o(int len, short extra, short hash, t_printf *data)
{
	int i;

	i = 0;
	while (data->width > i + len + extra + hash)
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	if (data->width > data->precision && hash == 1 && data->precision > len)
	{
		write(1, " ", 1);
		data->ret++;
	}
}

static void		flaghandler_o_space(t_printf *data, int len,
							short hash, short extra)
{
	int	i;

	i = 0;
	while (data->width > i + len + extra + hash &&
				(data->zero == 0 || data->dot == 1))
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	if (data->width > data->precision && hash == 1 && data->precision > len)
	{
		write(1, " ", 1);
		data->ret++;
	}
}

static void		put_o(unsigned long long d)
{
	char	*temp;

	temp = ft_itoabase(d, 8);
	ft_putstr(temp);
	free(temp);
}

void			flaghandler_o(t_printf *data, int len, short hash,
												unsigned long long d)
{
	short		extra;

	extra = 0;
	if (data->precision > len)
		extra = data->precision - len;
	if (data->minus == 0)
		flaghandler_o_space(data, len, hash, extra);
	flaghandler_o_zero(data, extra, len, hash);
	if (data->precision == 0 && data->dot == 1 && d == 0)
	{
		if (data->width != 0 && data->hash == 0)
			write(1, " ", 1);
		else if (data->hash == 0)
			data->ret--;
		else
			write(1, "0", 1);
	}
	else
		put_o(d);
	data->ret += len;
	if (data->minus == 1)
		minus_o(len, extra, hash, data);
}
