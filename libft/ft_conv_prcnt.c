/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_prcnt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 18:15:12 by tide-jon       #+#    #+#                */
/*   Updated: 2019/06/17 18:48:37 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prcnt_helper(t_printf *data, char c)
{
	int i;

	i = 1;
	while (i < data->width)
	{
		write(1, &c, 1);
		i++;
		data->ret++;
	}
}

void		conv_prcnt(t_printf *data)
{
	if (data->zero == 1 && data->minus == 0)
		prcnt_helper(data, '0');
	else if (data->minus == 0)
		prcnt_helper(data, ' ');
	write(1, "%", 1);
	if (data->minus == 1)
		prcnt_helper(data, ' ');
	data->ret++;
}
