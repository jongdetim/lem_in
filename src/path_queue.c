/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_queue.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 15:25:57 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/30 15:27:58 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	pop_queue_path(t_path_queue **queue)
{
	t_path_queue	*temp;

	temp = (*queue)->next;
	free(*queue);
	*queue = temp;
}

void	enqueue_path(t_hash_graph **path, t_lem_in *data)
{
	t_path_queue *current;

	current = data->end_of_queue;
	current->next = (t_path_queue*)malloc(sizeof(t_path_queue));
	current->next->path = path;
	current->next->next = NULL;
	data->end_of_queue = current->next;
}
