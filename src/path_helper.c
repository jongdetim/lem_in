/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_helper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 15:21:35 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/30 15:28:27 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		allocate_paths(t_lem_in *data)
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

void		extend_path(t_lem_in *data, t_path_queue *queue,
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

void		delete_path(t_hash_graph **path)
{
	int i;

	i = 0;
	while (path[i] != NULL)
	{
		path[i] = NULL;
		i++;
	}
}
