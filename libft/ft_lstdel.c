/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:03:25 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/30 16:55:40 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nextlink;
	t_list	*currentlink;

	if (alst)
	{
		currentlink = *alst;
		while (currentlink != NULL)
		{
			del(currentlink->content, currentlink->content_size);
			nextlink = currentlink->next;
			free(currentlink);
			currentlink = nextlink;
		}
		*alst = NULL;
	}
}
