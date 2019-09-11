/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhitespace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 13:26:50 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/26 13:36:02 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(char c)
{
	return (c == '\t' || c == '\n' || c == '\f' ||
			c == '\r' || c == '\v' || c == ' ');
}
