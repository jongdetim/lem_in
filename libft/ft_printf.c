/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 17:11:02 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:54:47 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		init_data(t_printf *data)
{
	data->precision = 0;
	data->width = 0;
	data->type = '0';
	data->zero = 0;
	data->dot = 0;
	data->space = 0;
	data->hash = 0;
	data->minus = 0;
	data->plus = 0;
	data->length = '0';
}

void		set_argnum(t_printf *data, int d)
{
	int i;

	i = 0;
	va_copy(data->args, data->backup);
	while (i < d - 1)
	{
		(void)va_arg(data->args, int);
		i++;
	}
}

/*
**	saves the found integer as width, argnum$ or .precision
*/

static void	save_int(t_printf *data, int d)
{
	if (*(data->format) == '$')
	{
		set_argnum(data, d);
		data->format++;
	}
	else if (data->dot == 1)
		data->precision = d;
	else
		data->width = d;
	data->format--;
}

/*
**	processes integers after % and deal with '0' flag.
*/

void		process_int(t_printf *data)
{
	int		i;
	int		j;
	int		d;
	char	*s;

	i = 0;
	j = 0;
	while (data->format[i] >= '0' && data->format[i] <= '9')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		s[j] = *(data->format);
		data->format++;
		j++;
	}
	s[i] = '\0';
	d = ft_atoi(s);
	free(s);
	save_int(data, d);
}

int			ft_printf(const char *restrict format, ...)
{
	t_printf	*data;
	char		*str;
	int			ret;

	data = (t_printf*)malloc(sizeof(t_printf));
	data->format = ft_strdup(format);
	str = data->format;
	data->ret = 0;
	build_dispatcher(data);
	va_start(data->args, format);
	va_copy(data->backup, data->args);
	parser(data);
	va_end(data->args);
	free(str);
	ret = data->ret;
	free(data);
	return (ret);
}
