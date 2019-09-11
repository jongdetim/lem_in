/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 13:37:40 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/11 13:55:09 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	help_trim_graph(t_hash_graph *temp, t_hash_graph *node, \
															t_neighbours *nb)
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

void	trim_graph(t_hash_graph *node)
{
	t_hash_graph	*temp;
	t_neighbours	*nb;

	temp = NULL;
	if (node->neighbours->neighbours == NULL)
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
		help_trim_graph(temp, node, nb);
}
