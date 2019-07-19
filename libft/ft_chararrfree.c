/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chararrfree.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 17:35:49 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/14 16:21:40 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chararrfree(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i] != NULL)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}
