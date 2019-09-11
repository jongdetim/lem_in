/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combos2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:27:09 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/11 13:58:39 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int				check_improvement(int j, t_lem_in *data, int *arr)
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

void			get_combo_max(t_lem_in *data)
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

float			calculate_steps(t_lem_in *data, int *arr)
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
