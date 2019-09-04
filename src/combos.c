/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:27:09 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/04 16:07:22 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	get_combo_max(t_lem_in *data)
{
	int 			i;
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

static float	calculate_steps(t_lem_in *data, int *arr)
{
	int		k;
	int		l;
	int		nodes;
	int		paths;
	float	steps;

	k = 0;
	paths = 0;
	nodes = 0;
	while (k < data->combo_max && arr[k] != -1)
	{
		l = 0;
		while (data->complete[arr[k]][l + 2] != NULL && l < PATH_LEN - 2)
			l++;
		nodes += l;
		paths++;
		k++;
	}
	steps = (float)(data->amount + nodes) / (float)paths;
	return (steps);
}

static int	check_improvement(int j, t_lem_in *data, int *arr)
{
	float	steps;
	int		k;

	k = 0;
	steps = calculate_steps(data, arr);
	while (arr[k] != -1)
		k++;
	arr[k] = j;
	if (calculate_steps(data, arr) < steps)
		return (1);
	arr[k] = -1;
	return (0);
}

static int	check_overlap(int j, t_lem_in *data, int *arr)
{
	int	k;
	int l;
	int m;

	k = 0;
	while (data->complete[arr[k]] != NULL && arr[k] != j)
	{
		l = 1;
		while (data->complete[arr[k]][l + 1] != NULL && l < PATH_LEN - 1)
		{
			m = 1;
			while (data->complete[j][m + 1] != NULL && m < PATH_LEN - 1)
			{
				if (data->complete[arr[k]][l] == data->complete[j][m])
					return (0);
				m++;
			}
			l++;
		}
		k++;
	}
	return (1);
}

static void	combo_helper(int j, t_lem_in *data, int *arr)
{
	int k;

	k = 0;
	if (check_improvement(j, data, arr) == 1)
	{
		if (check_overlap(j, data, arr) != 1)
		{
			while (arr[k] != j)
				k++;
			arr[k] = -1;
		}
	}
}

static void	save_combo(t_lem_in *data, int *arr)
{
	float	steps;
	int		i;

	i = 0;
	steps = calculate_steps(data, arr);
	steps = (float)(int)(steps) == steps ? steps : (steps + 1);
	if ((int)steps < data->solution_steps || data->solution_steps == 0)
	{
		data->solution_steps = (int)steps;
		if (data->solution == NULL)
			data->solution = (t_hash_graph***)ft_memalloc(sizeof(t_hash_graph**)
													* (data->combo_max + 1));
		while (i < data->combo_max && arr[i] != -1)
		{
			data->solution[i] = data->complete[arr[i]];
			i++;
		}
		data->solution[i] = NULL;
	}
}

static void	find_combos(t_lem_in *data)
{
	int				arr[data->combo_max];
	int				j;
	int				i;

	i = 0;
	while (data->complete[i] != NULL)
	{
		j = 0;
		while(j < data->combo_max)
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
}

void		choose_combos(t_lem_in *data)
{
	while (data->complete[data->path_num] != NULL)
		data->path_num++;
	get_combo_max(data);
	find_combos(data);
}
