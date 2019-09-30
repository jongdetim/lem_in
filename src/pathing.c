/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pathing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 15:03:24 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/30 15:25:37 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		take_next_lowest(t_path_queue *queue,
				int max, t_pathing_params *params)
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

void		take_lowest_levels(t_lem_in *data, t_path_queue *queue,
										t_pathing_params *params)
{
	int				max;

	extend_path(data, queue, params->save, 0);
	if (params->save->node->type == 2)
		return ;
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
		max++;
		params->n--;
	}
}

static void	save_lowest_step(t_path_queue *queue,
		t_neighbours *nb, t_pathing_params *params)
{
	int	j;

	j = 0;
	while (j < params->i)
	{
		if (queue->path[j] == nb->node)
			break ;
		j++;
	}
	if (j == params->i && nb->node->type != 1 &&
				nb->node->visited != MAX_VISITS)
	{
		if (nb->node->level < params->lowest)
		{
			params->lowest = nb->node->level;
			params->save = nb;
		}
		params->n++;
	}
}

static void	deal_step(t_lem_in *data, t_path_queue *queue,
											t_neighbours *nb)
{
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
		save_lowest_step(queue, nb, &params);
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
