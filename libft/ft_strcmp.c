/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:12:32 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/29 15:58:13 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	if (s1 != s2)
	{
		index = 0;
		while (s1[index] || s2[index])
		{
			if (s2[index] == '\0')
				return (1);
			if (s1[index] == '\0')
				return (-1);
			if (((unsigned char)s1[index] - (unsigned char)s2[index]) != 0)
				return ((unsigned char)s1[index] - (unsigned char)s2[index]);
			else
				index++;
		}
	}
	return (0);
}
