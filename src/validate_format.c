/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_format.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:00:41 by awehlbur       #+#    #+#                */
/*   Updated: 2019/10/17 15:53:11 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	valid_number(char *str, char c, int *amt)
{
	char	*orig;
	int		count;

	orig = str;
	count = 0;
	if (!ft_isdigit(*str) && *str != '-')
		return (0);
	while (*str != c)
	{
		if (!*str || (!ft_isdigit(*str) && !(count == 0 && *str == '-')))
			return (0);
		++str;
		count++;
	}
	*amt = str - orig;
	return (1);
}

static int	valid_str(char *str, char *format, int *amt)
{
	char	*orig;

	orig = str;
	if (ft_iswhitespace(*str))
		return (0);
	while (*str != *format)
	{
		if (!*str || ft_iswhitespace(*str))
			return (0);
		++str;
	}
	*amt = str - orig;
	return (1);
}

static int	validate_format(char *format, char *str, int *amt)
{
	++format;
	if (*format == 'd')
		if (!valid_number(str, *(format + 1), amt))
			return (0);
	if (*format == 's')
		if (!valid_str(str, format + 1, amt))
			return (0);
	return (1);
}

int			ft_validate_format(char *format, char *str)
{
	int		amt;

	if (!format || !str)
		return (0);
	while (*format && *str)
	{
		if (*format == '%')
		{
			if (!validate_format(format, str, &amt))
				return (0);
			format += 2;
			str += amt;
		}
		else
		{
			if (*format != *str)
				return (0);
			++format;
			++str;
		}
	}
	if (*format || *str)
		return (0);
	return (1);
}
