/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_graph.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 18:43:47 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 20:06:53 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	get_node_type(t_hash_graph *node, t_lem_in_lst *current,
														t_lem_in *data)
{
	node->type = current->type;
	if (node->type == 1)
		data->start = node;
	if (node->type == 2)
		data->end = node;
}

void		build_graph(t_lem_in *data)
{
	int				index;
	t_lem_in_lst	*current;
	t_hash_graph	*node;

	data->hashsize = ft_get_next_prime(data->nodes * HTABLE_SIZE);
	data->graph = (t_hash_graph*)ft_memalloc(sizeof(t_hash_graph) *
													data->hashsize);
	current = data->node_lst;
	while (current != NULL)
	{
		index = ft_hash_str(current->name, data->hashsize);
		node = &(data->graph[index]);
		if (node->key != NULL)
		{
			while (node->coll != NULL)
				node = node->coll;
			node->coll = (t_hash_graph*)ft_memalloc(sizeof(t_hash_graph));
			node = node->coll;
		}
		node->key = current->name;
		get_node_type(node, current, data);
		node->coll = NULL;
		current = current->next;
	}
}
