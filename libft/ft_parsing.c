/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:30:00 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:55:24 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	checks if conversion type has been found
**	if the current character is a conversion type it is saved in data->type
*/

static int	get_conv(t_printf *data)
{
	if (data->type == '0')
	{
		if (ft_strchr("diouxXcspegf%", *(data->format)) != NULL)
		{
			data->type = *(data->format);
			return (1);
		}
		return (0);
	}
	else
	{
		return (1);
	}
}

/*
**	'b' = long long; 'c' = character
*/

static void	get_length(t_printf *data)
{
	if (ft_strchr("lhL", *(data->format)) != NULL)
	{
		if (data->length == '0')
		{
			data->length = *(data->format);
		}
		else if (data->length == 'h')
			data->length = 'c';
		else if (data->length == 'l')
			data->length = 'b';
	}
}

static void	deal_astrix(t_printf *data)
{
	if (data->dot == 0)
	{
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus = 1;
			data->width *= -1;
		}
	}
	else
	{
		data->precision = va_arg(data->args, int);
		if (data->precision < 0)
		{
			data->precision = 0;
			data->dot = 0;
		}
	}
}

static void	parse_arg(t_printf *data)
{
	data->format++;
	while (*(data->format) != '\0' && get_conv(data) == 0)
	{
		if (*(data->format) == '.')
			data->dot = 1;
		if (*(data->format) == '*')
			deal_astrix(data);
		if (*(data->format) == ' ')
			data->space = 1;
		if (*(data->format) == '-')
			data->minus = 1;
		if (*(data->format) == '+')
			data->plus = 1;
		if (*(data->format) == '#')
			data->hash = 1;
		if (*(data->format) == '0' && data->dot == 0)
			data->zero = 1;
		if (*(data->format) >= '1' && *(data->format) <= '9')
			process_int(data);
		get_length(data);
		data->format++;
	}
	dispatcher(data);
}

void		parser(t_printf *data)
{
	while (*(data->format))
	{
		if (*(data->format) == '%')
		{
			init_data(data);
			parse_arg(data);
		}
		else
		{
			write(1, (data->format), 1);
			data->ret++;
		}
		if (*(data->format))
			data->format++;
	}
}
