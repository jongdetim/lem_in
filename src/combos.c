/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:27:09 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 20:16:44 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		get_combo_max(t_lem_in *data)
{
	int				i;
	t_neighbours	*nb;

	i = 0;
	nb = data->start->neighbours;
	while (nb != NULL)
	{
		i++;
		nb = nb->neighbours;
	}
	data->combo_max = i;
	i = 0;
	nb = data->end->neighbours;
	while (nb != NULL)
	{
		i++;
		nb = nb->neighbours;
	}
	if (data->combo_max > i)
		data->combo_max = i;
	if (data->path_num < data->combo_max)
		data->combo_max = data->path_num;
}

static void		save_combo(t_lem_in *data, int *arr)
{
	float	steps;
	int		i;

	i = 0;
	steps = calculate_steps(data, arr);
	steps = (float)(int)(steps) == steps ? steps : (steps + 1);
	if ((int)steps < data->solution_steps)
	{
		data->solution_steps = (int)steps;
		if (data->solution == NULL)
			data->solution = (t_hash_graph***)malloc(sizeof(t_hash_graph**)
													* (data->combo_max + 1));
		while (i < data->combo_max && arr[i] != -1)
		{
			data->solution[i] = data->complete[arr[i]];
			i++;
		}
		data->solution[i] = NULL;
	}
}

static int		find_combos(t_lem_in *data)
{
	int				arr[data->combo_max];
	int				j;
	int				i;

	i = 0;
	while (data->complete[i] != NULL)
	{
		j = 0;
		while (j < data->combo_max)
		{
			arr[j] = -1;
			j++;
		}
		j = 0;
		arr[0] = i;
		while (data->complete[j] != NULL && arr[data->combo_max - 1] == -1)
		{
			if (i != j)
				combo_helper(j, data, arr);
			j++;
		}
		save_combo(data, arr);
		i++;
	}
	return (i - 1);
}

void			choose_combos(t_lem_in *data)
{
	while (data->complete[data->path_num] != NULL)
		data->path_num++;
	get_combo_max(data);
	find_combos(data);
}
