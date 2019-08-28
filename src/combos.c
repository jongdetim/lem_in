/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:27:09 by tide-jon       #+#    #+#                */
/*   Updated: 2019/08/28 19:44:42 by tide-jon      ########   odam.nl         */
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
													* data->combo_len);
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

void		choose_combos(t_lem_in *data)
{
	while (data->complete[data->path_num] != NULL)
		data->path_num++;
	get_combo_len(data);
	while (data->combo_len != 0)
	{
		find_combos(data);
		data->combo_len--;
	}
}