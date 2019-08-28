/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 12:34:38 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/28 14:50:39 by tide-jon      ########   odam.nl         */
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

static void		enqueue(t_bfs_queue *queue, t_hash_graph *node)
{
	t_bfs_queue *current;

	if (node->visited == 0)
	{
		node->visited = 1;								// set to visited
		current = queue;								// set current to current node
		while (current->next != NULL)					// look if current
			current = current->next;
		current->next = (t_bfs_queue*)malloc(sizeof(t_bfs_queue));
		current->next->node = node;
		current->next->next = NULL;
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

	queue = (t_bfs_queue*)malloc(sizeof(t_bfs_queue)); 	// malloc queue linked list
	queue->next = NULL;
	node = data->end;
	node->visited = 1;
	queue->node = node;								// set queue node to start
	while (queue != NULL)								// check of er een node in zit (eerste keer dus start checken)
	{
		node = queue->node;								// ga naar de volgende node
		neighbours = node->neighbours;				// set neighbours to the neighbours node
		while (neighbours != NULL)						// check if there are any neighbours
		{
			level_graph(node, neighbours);
			enqueue(queue, neighbours->node);			// go in queue, give current node and neighbouring node
			neighbours = neighbours->neighbours;
		}
		pop_queue(&queue);
		if (node->type == 0)
			trim_graph(node);
	}
}