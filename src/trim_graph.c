/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 19:56:04 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/22 16:13:58 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	trim_graph(t_hash_graph *node)
{
	t_hash_graph	*temp;
	t_neighbours	*nb;

	temp = NULL;
	ft_putendl(node->key);
	if (node->neighbours->neighbours == NULL) // <-- alleen 1 connectie?
	{
		ft_putendl("dingetje");
		temp = node;
		node = node->neighbours->node;
	}
	write(1, "666", 3);
	nb = node->neighbours;
	write(1, "1234", 4);
	if (temp != NULL && nb->node == temp)
	{
		write(1, "DING", 4);
		node->neighbours = node->neighbours->neighbours;
		ft_putendl("wew.lad");
		if (node->type == 0)
			trim_graph(node);
	}
	else
	{
		while (temp != NULL && nb->neighbours != NULL)
		{
			if (nb->neighbours->node == temp)
			{
				ft_putendl("test");
				nb->neighbours = nb->neighbours->neighbours;
				if (node->type == 0)
					trim_graph(node);
				break ;
			}
		nb = nb->neighbours;
		}
	}
	write(1, "xxx", 3);
}
