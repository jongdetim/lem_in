/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:27:09 by tide-jon       #+#    #+#                */
/*   Updated: 2019/08/29 20:11:32 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	get_combo_len(t_lem_in *data)
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
	data->combo_len = i;
	i = 0;
	nb = data->end->neighbours;
	while (nb != NULL)
	{
		i++;
		nb = nb->neighbours;
	}
	if (data->combo_len > i)
		data->combo_len = i;
	if (data->path_num < data->combo_len)
		data->combo_len = data->path_num;
}

static void	save_combo(t_lem_in *data, int *arr)
{
	t_combos	*lst;
	int			i;

	i = 0;
	lst = (t_combos*)ft_memalloc(sizeof(t_combos));
	lst->combo = (t_hash_graph***)ft_memalloc(sizeof(t_hash_graph**)
												* data->combo_len + 1);
	while (i < data->combo_len)
	{
		lst->combo[i] = data->complete[arr[i]];
		i++;
	}
	lst->next = data->combo_lst;
	data->combo_lst = lst;
}

static void	combo_helper(int *i, int *r, t_lem_in *data, int *arr)
{
	(arr)[*r] = *i;
	if (*r == data->combo_len - 1)
	{
		save_combo(data, arr);
		(*i)++;
	}
	else
	{
		*i = (arr)[*r] + 1;
		(*r)++;
	}
}

static void	find_combos(t_lem_in *data)
{
	int			arr[data->combo_len];
	int			r;
	int			i;

	r = 0;
	i = 0;
	while (r >= 0)
	{
		if (i <= (data->path_num + (r - data->combo_len)))
			combo_helper(&i, &r, data, arr);
		else
		{
			r--;
			if (r >= 0)
				i = arr[r] + 1;
		}
	}
}

int			select_helper(t_combos *drone, int i, int j)
{
	t_hash_graph	*compare;

	compare = drone->combo[j][i];
	while (drone->combo[j + 1] != NULL)
	{
		j++;
		while (drone->combo[j][i + 1] != NULL && i < PATH_LEN - 1)
		{
			if (drone->combo[j][i] == compare)
				return (0);
			i++;
		}
		i = 1;
	}
	return (1);
}

int			select_combo(t_combos *drone)
{
	int			i;
	int			j;

	j = 0;
	while (drone->combo[j + 1] != NULL)
	{
		i = 1;
		while (drone->combo[j][i + 1] != NULL && i < PATH_LEN - 1)
		{
			if (select_helper(drone, i, j) == 0)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void		eval_combo(t_combos *drone, t_lem_in *data)
{
	int			steps;
	int			paths;
	int			nodes;
	int			i;

	steps = 0;
	paths = 0;
	nodes = 0;
	i = 0;
	while (drone->combo[paths] != NULL)
	{
		i = 0;
		while (drone->combo[paths][i + 1] != NULL && i < PATH_LEN - 1)
			i++;
		nodes += i;
		paths++;
	}
	steps = (data->amount + nodes) / paths;
	if (data->solution == NULL || steps < data->solution_steps)
	{
		data->solution = drone->combo;
		data->solution_steps = steps;
	}
	ft_printf("%i steps\n%i nodes\n %i paths\n\n", steps, nodes, paths);
}

void		choose_combos(t_lem_in *data)
{
	t_combos	*drone;

	while (data->complete[data->path_num] != NULL)
		data->path_num++;
	get_combo_len(data);
	while (data->combo_len != 0)
	{
		find_combos(data);
		data->combo_len--;
	}
	drone = data->combo_lst;
	while (drone != NULL)
	{
		if (select_combo(drone) == 1)
			eval_combo(drone, data);
		drone = drone->next;
	}
}