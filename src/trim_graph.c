/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 19:56:04 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/20 20:09:42 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	delete_node(t_hash_graph *temp, t_neighbours *nb, t_neighbours *t_nb)
{
	t_nb = nb->neighbours;
	nb->neighbours = nb->neighbours->neighbours;
	if (temp == NULL)
		return ;
	free(temp->neighbours);
	free(t_nb->neighbours);
}

void	trim_graph(t_hash_graph *node)
{
	t_hash_graph	*temp;
	t_neighbours	*neighbour;
	t_neighbours	*neigh_temp;

	temp = NULL;
	neigh_temp = NULL;
	if (node->neighbours->neighbours == NULL)
	{
		temp = node;
		node = node->neighbours->node;
	}
	neighbour = node->neighbours;
	if (temp != NULL && neighbour->neighbours->node == temp)
	{
		delete_node(temp, neighbour, neigh_temp);
		trim_graph(node);
	}
	while (temp != NULL && neighbour->neighbours != NULL)
	{
		if (neighbour->neighbours->node == temp)
		{
			delete_node(temp, neighbour, neigh_temp);
			trim_graph(node);
		}
		neighbour = neighbour->neighbours;
	}
}