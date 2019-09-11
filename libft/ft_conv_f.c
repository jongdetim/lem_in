/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 19:56:57 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/01 17:34:45 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			flaghandler_f_zeros(t_printf *data, char *str, int zeros)
{
	char	*zerostr;
	int		min;
	char	*temp;

	min = 0;
	if (str[0] == '-')
		min = 1;
	zerostr = ft_strnew(zeros);
	zerostr = ft_memset(zerostr, '0', zeros);
	temp = str;
	str = ft_strjoin(zerostr, str);
	if (min == 1 && zerostr[0] == '0')
	{
		str[0] = '-';
		str[zeros] = '0';
	}
	free(zerostr);
	free(temp);
	data->ret += zeros;
	ft_putstr(str);
}

static void			flaghandler2_f(t_printf *data, int len, char *str)
{
	int		zeros;

	zeros = 0;
	if (data->zero == 0)
	{
		while (data->width > len)
		{
			write(1, " ", 1);
			data->ret++;
			data->width--;
		}
		if (data->minus == 0)
			ft_putstr(str);
	}
	else if (data->minus == 0)
	{
		while (data->width > len)
		{
			if (data->zero == 1)
				zeros++;
			data->width--;
		}
		flaghandler_f_zeros(data, str, zeros);
	}
}

static void			flaghandler_f(t_printf *data, int len, char *str)
{
	short	min;

	min = 0;
	if (str[0] == '-')
		min = 1;
	if (data->space == 1 && data->plus == 0 && min == 0)
	{
		write(1, " ", 1);
		data->width--;
		data->ret++;
	}
	if (data->plus == 1 && min == 0)
	{
		write(1, "+", 1);
		data->width--;
		data->ret++;
	}
	if (data->minus == 1)
		ft_putstr(str);
	flaghandler2_f(data, len, str);
	data->ret += len;
}

void				conv_f(t_printf *data)
{
	char		*str;
	long double	d;
	int			len;

	if (data->length == 'L')
		d = va_arg(data->args, long double);
	else
		d = va_arg(data->args, double);
	if (data->dot)
		str = ft_ftoa(d, data->precision);
	else
		str = ft_ftoa(d, 6);
	len = ft_strlen(str);
	if (str[len - 1] == '.' && data->hash == 0)
	{
		len--;
		str[len] = '\0';
	}
	flaghandler_f(data, len, str);
}
