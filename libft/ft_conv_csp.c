/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_csp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 20:19:15 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:12:50 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		conv_c(t_printf *data)
{
	int		i;
	char	c;

	i = 1;
	c = va_arg(data->args, int);
	if (data->minus == 1)
	{
		write(1, &c, 1);
		data->ret++;
	}
	while (i < data->width)
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	if (data->minus == 0)
	{
		write(1, &c, 1);
		data->ret++;
	}
}

static char	*conv_s_null(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 6 + 1);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

void		conv_s(t_printf *data)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(data->args, char*);
	if (str == NULL)
		str = conv_s_null();
	else
		str = ft_strdup(str);
	if ((int)ft_strlen(str) > data->precision && data->dot == 1)
		str[data->precision] = '\0';
	if (data->minus == 1)
		ft_putstr((const char*)str);
	while (i < data->width - (int)ft_strlen(str))
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	if (data->minus == 0)
		ft_putstr((const char*)str);
	data->ret += ft_strlen(str);
	free(str);
}

void		conv_p(t_printf *data)
{
	unsigned long	addr;
	char			*str;
	char			*temp;
	int				i;

	i = 0;
	addr = va_arg(data->args, unsigned long);
	temp = ft_itoabase(addr, 16);
	str = ft_strjoin("0x", temp);
	free(temp);
	while (data->width > i + (int)ft_strlen(str) && data->minus == 0)
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	ft_putstr(str);
	data->ret += ft_strlen(str);
	while (data->width > i + (int)ft_strlen(str) && data->minus == 1)
	{
		write(1, " ", 1);
		i++;
		data->ret++;
	}
	free(str);
}
