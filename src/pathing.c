/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pathing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 15:03:24 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 21:14:12 by tide-jon      ########   odam.nl         */
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

static void	enqueue_path(t_hash_graph **path, t_lem_in *data)
{
	t_path_queue *current;

	current = data->end_of_queue;
	current->next = (t_path_queue*)malloc(sizeof(t_path_queue));
	current->next->path = path;
	current->next->next = NULL;
	data->end_of_queue = current->next;
}

static void	allocate_paths(t_lem_in *data)
{
	int	i;
	int	j;

	i = 0;
	data->paths = (t_hash_graph***)ft_memalloc(sizeof(t_hash_graph**)
														* (PATH_NUMS + 1));
	while (i < PATH_NUMS)
	{
		data->paths[i] = (t_hash_graph**)ft_memalloc(sizeof(t_hash_graph*)
															* (PATH_LEN + 1));
		j = 0;
		while (j <= PATH_LEN)
		{
			data->paths[i][j] = NULL;
			j++;
		}
		i++;
	}
	data->complete = (t_hash_graph***)ft_memalloc(sizeof(t_hash_graph**)
														* (PATH_NUMS + 1));
}

static void	check_finish(t_hash_graph **path,
									t_neighbours *nb, t_lem_in *data)
{
	int	i;

	i = 0;
	if (nb->node->type != 2)
		enqueue_path(path, data);
	else
	{
		while (data->complete[i] != NULL)
			i++;
		data->complete[i] = path;
	}
}

static void	extend_helper(t_lem_in *data, t_path_queue *queue,
										int i, t_neighbours *nb)
{
	int	j;

	j = 0;
	while (data->paths[i][0] != NULL)
	{
		i++;
		if (i == PATH_NUMS)
			return ;
	}
	while (queue->path[j + 1] != NULL)
	{
		data->paths[i][j] = queue->path[j];
		j++;
		if (j == PATH_LEN)
			return ;
	}
	data->paths[i][j] = nb->node;
	check_finish(data->paths[i], nb, data);
}

static void	extend_path(t_lem_in *data, t_path_queue *queue,
										t_neighbours *nb, int n)
{
	int i;

	i = 0;
	if (nb->node->type != 2)
		nb->node->visited++;
	if (n == 0)
	{
		while (queue->path[i] != NULL)
		{
			i++;
			if (i == PATH_LEN)
				return ;
		}
		queue->path[i] = nb->node;
		check_finish(queue->path, nb, data);
	}
	else
		extend_helper(data, queue, i, nb);
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

void	take_next_lowest(t_path_queue *queue, int max, t_pathing_params *params)
{
	int	j;
	
	j = 0;
	while (j < params->i)
	{
		if (queue->path[j] == params->nb->node)
			break ;
		j++;
	}
	if (j == params->i && params->nb->node->type != 1 && params->nb->node->level
					< params->lowest && params->nb->node->visited != MAX_VISITS)
	{
		j = 0;
		while (j <= max)
		{
			if (params->nb == params->mem[j])
				break ;
			j++;
		}
		if (j > max)
		{
			params->lowest = params->nb->node->level;
			params->save = params->nb;
		}
	}
}

void	take_lowest_levels(t_lem_in *data, t_path_queue *queue,
										t_pathing_params *params)
{
	int				max;

	extend_path(data, queue, params->save, 0);
	max = 0;
	while (max < 5 && params->n > 0)
	{
		params->mem[max] = params->save;
		params->nb = queue->path[params->i]->neighbours;
		params->lowest = INT_MAX;
		while (params->nb != NULL)
		{
			take_next_lowest(queue, max, params);
			params->nb = params->nb->neighbours;
		}
		extend_path(data, queue, params->save, params->n);
		if (params->save->node->type == 2)
			return ;
		max++;
		params->n--;
	}
}

static void	deal_step(t_lem_in *data, t_path_queue *queue,
											t_neighbours *nb)
{
	int					j;
	t_pathing_params	params;

	params.i = 0;
	params.n = -1;
	params.lowest = INT_MAX;
	while (queue->path[params.i + 1] != NULL)
	{
		params.i++;
		if (params.i == PATH_LEN - 1)
			return ;
	}
	nb = queue->path[params.i]->neighbours;
	while (nb != NULL)
	{
		j = 0;
		while (j < params.i)
		{
			if (queue->path[j] == nb->node)
				break ;
			j++;
		}
		if (j == params.i && nb->node->type != 1 &&
					nb->node->visited != MAX_VISITS) 
		{
			if (nb->node->level < params.lowest)
			{
				params.lowest = nb->node->level;
				params.save = nb;
			}
			params.n++;
		}
		if (params.i == 0 && params.n >= 0)
			extend_path(data, queue, nb, params.n);
		nb = nb->neighbours;
	}
	if (params.i > 0 && params.n >= 0)
		take_lowest_levels(data, queue, &params);
	else if (params.n == -1)
		delete_path(queue->path);
}

void		find_paths(t_lem_in *data)
{
	t_neighbours	*nb;
	t_path_queue	*queue;

	nb = NULL;
	allocate_paths(data);
	data->paths[0][0] = data->start;
	queue = (t_path_queue*)malloc(sizeof(t_path_queue));
	queue->path = data->paths[0];
	queue->next = NULL;
	data->end_of_queue = queue;
	while (queue != NULL)
	{
		deal_step(data, queue, nb);
		pop_queue_path(&queue);
	}
}
