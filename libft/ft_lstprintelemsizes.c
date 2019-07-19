/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstprintelemsizes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 20:28:35 by tide-jon       #+#    #+#                */
/*   Updated: 2019/04/01 18:18:41 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintelemsizes(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putnbr((int)(lst->content_size));
		write(1, "\n", 1);
		lst = lst->next;
	}
}
