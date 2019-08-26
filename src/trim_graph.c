/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 19:56:04 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/26 16:53:47 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	trim_graph(t_hash_graph *node)
{
	t_hash_graph	*temp;
	t_neighbours	*nb;

	temp = NULL;
	if (node->neighbours->neighbours == NULL) // <-- alleen 1 connectie?
	{
		temp = node;
		node = node->neighbours->node;
	}
	nb = node->neighbours;
	if (temp != NULL && nb->node == temp)
	{
		node->neighbours = node->neighbours->neighbours;
		if (node->type == 0)
			trim_graph(node);
	}
	else
	{
		while (temp != NULL && nb->neighbours != NULL)
		{
			if (nb->neighbours->node == temp)
			{
				nb->neighbours = nb->neighbours->neighbours;
				if (node->type == 0)
					trim_graph(node);
				break ;
			}
		nb = nb->neighbours;
		}
	}
}
