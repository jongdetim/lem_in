/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 19:56:04 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/21 16:24:34 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	trim_graph(t_hash_graph *node)
{
	t_hash_graph	*temp;
	t_neighbours	*nb;

	if (node->neighbours->neighbours == NULL) // <-- alleen 1 connectie?
	{
		temp = node;
		node = node->neighbours->node;
	}
	nb = node->neighbours;
	if (temp != NULL && nb->node == temp)
	{
		node->neighbours = node->neighbours->neighbours;
		trim_graph(node);
	}
	else
	{
		while (temp != NULL && nb->neighbours != NULL)
		{
			if (nb->neighbours->node == temp)
			{
				node->neighbours->neighbours =
				node->neighbours->neighbours->neighbours;
				trim_graph(node);
				break ;
			}
		nb = nb->neighbours;
		}
	}
}
