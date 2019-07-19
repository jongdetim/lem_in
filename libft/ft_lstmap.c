/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 17:46:48 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/30 20:12:07 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*current_elem;

	if (!lst || !f)
		return (NULL);
	newlist = f(lst);
	if (!newlist)
		return (NULL);
	current_elem = newlist;
	while (lst->next != NULL)
	{
		lst = lst->next;
		current_elem->next = f(lst);
		if (!(current_elem->next))
			return (NULL);
		current_elem = current_elem->next;
	}
	current_elem->next = NULL;
	return (newlist);
}
