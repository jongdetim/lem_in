/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dispatcher.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:28:40 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/28 17:29:41 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dispatcher(t_printf *data)
{
	int		i;
	char	*str;

	str = "cspdiouxXf%";
	i = 0;
	while (str[i])
	{
		if (str[i] == data->type)
		{
			data->arr[i](data);
			break ;
		}
		i++;
	}
}

void		build_dispatcher(t_printf *data)
{
	data->arr[0] = conv_c;
	data->arr[1] = conv_s;
	data->arr[2] = conv_p;
	data->arr[3] = conv_d;
	data->arr[4] = conv_d;
	data->arr[5] = conv_o;
	data->arr[6] = conv_u;
	data->arr[7] = conv_x;
	data->arr[8] = conv_x;
	data->arr[9] = conv_f;
	data->arr[10] = conv_prcnt;
}
