/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 20:03:05 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/03 20:05:50 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	retnum(char *str, int i, int len)
{
	char	*temp;
	int		ret;

	temp = ft_strsub(str, i - len, (size_t)len);
	ret = ft_atoi(temp);
	free(temp);
	return (ret);
}

static void	set_value(int *i, int *counter, int *len)
{
	*i = 0;
	*counter = 1;
	*len = 0;
}

int			ft_getnum(char *str, int num)
{
	int		i;
	int		counter;
	int		len;

	set_value(&i, &counter, &len);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			len++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				len++;
				i++;
			}
			if (counter == num)
				return (retnum(str, i, len));
			counter++;
			len = 0;
		}
		else
			i++;
	}
	return (0);
}
