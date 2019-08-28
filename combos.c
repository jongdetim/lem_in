/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 15:27:09 by tide-jon       #+#    #+#                */
/*   Updated: 2019/08/28 16:51:52 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	get_path_num(t_lem_in *data)
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
	data->path_num = i;
	i = 0;
	nb = data->end->neighbours;
	while (nb != NULL)
	{
		i++;
		nb = nb->neighbours;
	}
	if (data->path_num > i)
		data->path_num = i;
}

void	find_combos(t_lem_in *data, int start, int end, int index)
{
	if (index == end)
		return ;
	while (start < end && end - start + 1 >= data->path_num - index)
	{
		data->combo_lst->combo[start] = 
		find_combos(data, start + 1, end, index + 1);
		start++;
	}
}

void	choose_combos(t_lem_in *data)
{
	t_combos	*lst;
	int i;

	i = 0;
	while (data->complete[i] != NULL)
		i++;
	data->combo_lst = (t_combos*)ft_memalloc(sizeof(t_combos));
	get_path_num(data);
	find_combos(data, 0, i, 0);
}