/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 17:14:39 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/30 17:30:19 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*current_elem;

	current_elem = *alst;
	while (current_elem != NULL)
		current_elem = current_elem->next;
	current_elem = new;
	new->next = NULL;
}
