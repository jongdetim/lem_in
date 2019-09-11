/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help_build.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/19 15:13:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/11 13:59:27 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			ft_isprime(int n)
{
	int i;

	i = 2;
	if (n == 1 || n == 0)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int			get_next_prime(int n)
{
	while (n % 2 == 0)
		n++;
	while (!ft_isprime(n))
		n++;
	return (n);
}

int			ft_hash_str(char *key, int size)
{
	int index;
	int i;
	int key_len;

	i = 0;
	index = 0;
	if (key == NULL)
		return (-1);
	key_len = ft_strlen(key);
	while (key[i] != '\0')
	{
		index = (index) + (key[key_len - i - 1]) \
										* ((32 ^ i) + (index) * (i ^ 7));
		i++;
	}
	index = ft_abs(index);
	return (index % size);
}

int			check_edge(char *line)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (ft_iswhitespace(line[i]) == 1)
			return (0);
		if (line[i] == '-')
			count++;
		i++;
	}
	if (count == 1 && i > 2)
		return (1);
	else
		return (0);
}

int			check_node(char *line)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			count++;
		else if (count > 0 && (line[i] < '0' || line[i] > '9'))
			return (0);
		i++;
	}
	if (count == 2 && i > 4)
		return (1);
	else
		return (0);
}
