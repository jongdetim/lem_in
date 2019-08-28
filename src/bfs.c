/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 12:34:38 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/28 17:27:30 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		pop_queue(t_bfs_queue **queue)
{
	t_bfs_queue	*temp;

	temp = (*queue)->next;
	free(*queue);
	*queue = temp;
}

static void		enqueue(t_hash_graph *node, t_lem_in *data)
{
	t_bfs_queue *current;

	if (node->visited == 0)
	{
		node->visited = 1;
		current = data->end_of_bfs_queue;
		current->next = (t_bfs_queue*)malloc(sizeof(t_bfs_queue));
		current->next->node = node;
		current->next->next = NULL;
		data->end_of_bfs_queue = current->next;
	}
}

void			level_graph(t_hash_graph *node, t_neighbours *nb)
{
	if (nb->node->level == 0 || nb->node->level > node->level + 1)
		nb->node->level = node->level + 1;
}

void			bfs(t_lem_in *data)
{
	t_bfs_queue		*queue;
	t_hash_graph	*node;
	t_neighbours	*neighbours;

	queue = (t_bfs_queue*)malloc(sizeof(t_bfs_queue));
	queue->next = NULL;
	node = data->end;
	node->visited = 1;
	queue->node = node;	
	data->end_of_bfs_queue = queue;
	while (queue != NULL)
	{
		node = queue->node;
		neighbours = node->neighbours;
		while (neighbours != NULL)
		{
			level_graph(node, neighbours);
			enqueue(neighbours->node, data);
			neighbours = neighbours->neighbours;
		}
		pop_queue(&queue);
		if (node->type == 0)
			trim_graph(node);
	}
}
