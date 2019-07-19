/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 17:05:23 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/01 18:29:58 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ftoa_round(int i, char *str)
{
	if ((str)[i + 1] >= '5')
	{
		if (i == -1)
			return (1);
		if (str[i] < '9')
			str[i]++;
		else
			str[i] = '0';
		while (str[i] == '0' && i > 0)
		{
			i--;
			if (str[i] < '9')
				str[i]++;
			else
				str[i] = '0';
		}
		if (i == 0 && str[i] == '0')
			return (1);
		else
			return (0);
	}
	return (0);
}

static short	getafter(char **str, long double after, int afterpoint)
{
	int			i;
	char		*temp;
	char		*temp2;
	short		increment;
	long long	num;

	i = 0;
	*str = ft_strnew(0);
	while (i < afterpoint + 1)
	{
		temp = *str;
		after *= 10;
		num = (long long)after;
		temp2 = ft_itoa(num);
		*str = ft_strjoin(*str, temp2);
		after -= num;
		free(temp);
		free(temp2);
		i++;
	}
	i = afterpoint - 1;
	increment = ftoa_round(i, *str);
	(*str)[afterpoint] = '\0';
	return (increment);
}

static char		*getbefore(char *str, long double before, short increment)
{
	char		*beforestr;
	char		*temp;

	if (before >= 0)
		before += increment;
	else
		before -= increment;
	beforestr = ft_itoa(before);
	temp = beforestr;
	beforestr = ft_strjoin(beforestr, ".");
	free(temp);
	temp = str;
	str = ft_strjoin(beforestr, str);
	free(temp);
	return (str);
}

static char		*ftoa_naninf(long double f)
{
	char	*str;
	int		n;

	n = 3;
	if (f != f)
	{
		str = (char*)malloc(sizeof(char) * n + 1);
		str[0] = 'n';
		str[1] = 'a';
		str[2] = 'n';
		str[3] = '\0';
	}
	if (f > LDBL_MAX || f < -LDBL_MAX)
	{
		if (f < -LDBL_MAX)
			n = 4;
		str = (char*)malloc(sizeof(char) * n + 1);
		if (f < -LDBL_MAX)
			str[n - 4] = '-';
		str[n - 3] = 'i';
		str[n - 2] = 'n';
		str[n - 1] = 'f';
		str[n] = '\0';
	}
	return (str);
}

char			*ft_ftoa(long double f, int afterpoint)
{
	char		*str;
	long double	before;
	long double	after;
	short		increment;
	char		*temp;

	if (f != f || f > LDBL_MAX || f < -LDBL_MAX)
		return (ftoa_naninf(f));
	before = (long long)f;
	if (f < 0)
		after = (f - before) * -1;
	else
		after = f - before;
	increment = getafter(&str, after, afterpoint);
	str = getbefore(str, before, increment);
	if ((f < 0 && before == 0) || (f == 0 && 1 / f < 0))
	{
		temp = str;
		str = ft_strjoin("-", str);
		free(temp);
	}
	return (str);
}
