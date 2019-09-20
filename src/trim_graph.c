/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 19:56:04 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/16 19:52:58 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	trim_helper(t_neighbours *nb, t_hash_graph *node,
											t_hash_graph *temp)
{
	t_neighbours	*temp2;

	while (nb->neighbours != NULL)
	{
		if (nb->neighbours->node == temp)
		{
			temp2 = nb->neighbours;
			nb->neighbours = nb->neighbours->neighbours;
			free(temp2);
			if (node->type == 0)
				trim_graph(node);
			break ;
		}
		nb = nb->neighbours;
	}
}

void		trim_graph(t_hash_graph *node)
{
	t_hash_graph	*temp;
	t_neighbours	*nb;

	temp = NULL;
	if (node->conn == 1)
	{
		temp = node;
		node = node->neighbours->node;
		node->conn--;
	}
	nb = node->neighbours;
	if (temp != NULL && nb->node == temp)
	{
		node->neighbours = node->neighbours->neighbours;
		free(nb);
		if (node->type == 0)
			trim_graph(node);
	}
	else if (temp != NULL)
		trim_helper(nb, node, temp);
}
