/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pathing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 15:03:24 by tide-jon       #+#    #+#                */
/*   Updated: 2019/08/26 19:05:29 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	pop_queue_path(t_path_queue **queue)
{
	t_path_queue	*temp;

	temp = (*queue)->next;
	free(*queue);
	*queue = temp;
}

static void	enqueue_path(t_path_queue *queue, t_hash_graph **path)
{
	t_path_queue *current;

	current = queue;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_path_queue*)malloc(sizeof(t_path_queue));
	current->next->path = path;
	current->next->next = NULL;
}

static void	allocate_paths(t_lem_in *data)
{
	int	i;

	i = 0;
	data->paths = (t_hash_graph***)malloc(sizeof(t_hash_graph**)
																* PATH_NUMS);
	while (i < PATH_NUMS)
	{
		data->paths[i] = (t_hash_graph**)malloc(sizeof(t_hash_graph*)
																* PATH_LEN);
		i++;
	}
}

static void	check_finish(t_hash_graph **path, t_path_queue *queue,
												t_neighbours *nb)
{
	if (nb->node->type != 2)
		enqueue_path(queue, path);
	else
	{
		/* eventueel opslaan dat deze specifieke path klaar is zodat het
		makkelijker wordt om te zien welke paths compleet zijn aan het einde.
		denk bijvoorbeeld aan een array van PATH_NUMS met pointers naar paths
		die klaar zijn */
	}
}

static void	extend_path(t_hash_graph ***paths, t_path_queue *queue,
										t_neighbours *nb, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n == 0 && j < PATH_LEN)
	{
		while (queue->path[i] != NULL)			// <-- als (j == path_len - 1) moet geen nieuwe stap worden toegevoegd
			i++;
		queue->path[i] = nb->node;
		check_finish(queue->path, queue, nb);
	}
	else if (i < PATH_NUMS && j < PATH_LEN)
	{
		ft_putendl("a");
		while (paths[i][0] != NULL)
			i++;
		ft_putendl("b");
		while (queue->path[j + 1] != NULL)			// <-- als (j == path_len - 1) moet geen nieuwe stap worden toegevoegd
		{
			paths[i][j] = queue->path[j];
			j++;
		}
		ft_putendl("c");
		paths[i][j] = nb->node;
		check_finish(paths[i], queue, nb);
	}
}

static void	delete_path(t_hash_graph **path)
{
	int i;

	i = 0;
	while (path[i] != NULL)
	{
		path[i] = NULL;
		i++;
	}
}

static void	deal_step(t_hash_graph ***paths, t_path_queue *queue,
											t_neighbours *nb, int n)
{
	int	i;
	int	j;

	i = 0;
	while (queue->path[i + 1] != NULL)
		i++;
	nb = queue->path[i]->neighbours;
	while (nb != NULL)
	{
		ft_putendl("testme");
		j = 0;
		while (j < i)
		{
			if (queue->path[j] == nb->node)
				break ;
			j++;
		}
		if (j == i)
		{
			ft_putendl("123");
			extend_path(paths, queue, nb, n);
			n++;
		}
		nb = nb->neighbours;
	}
	if (n == 0)
		delete_path(queue->path);
}

void		find_paths(t_lem_in *data)
{
	t_neighbours	*nb;
	t_path_queue	*queue;
	int				n;

	nb = NULL;
	n = 0;
	allocate_paths(data);
	data->paths[0][0] = data->start;
	queue = (t_path_queue*)malloc(sizeof(t_path_queue));
	queue->path = data->paths[0];
	queue->next = NULL;

	while (queue != NULL)
	{
		ft_putendl("BWHUOY");
		deal_step(data->paths, queue, nb, n);
		ft_putendl("ding");
		pop_queue_path(&queue);
	}
}
