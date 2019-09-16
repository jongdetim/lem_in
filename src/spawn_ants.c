/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spawn_ants.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 19:24:32 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 19:56:54 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	spawn_helper(int *j, int *spread, t_lem_in *data, t_ant **ant_list)
{
	if ((*ant_list)->room != NULL)
	{
		(*ant_list)->next = (t_ant*)ft_memalloc(sizeof(t_ant));
		(*ant_list) = (*ant_list)->next;
	}
	(*ant_list)->room = data->solution[*j];
	spread[*j]--;
	data->amount--;
}

void		spawn_ants(t_ant *ant_list, int *spread, int i, t_lem_in *data)
{
	static int	ant_num;
	int			j;

	j = 0;
	while (ant_list->next != NULL)
		ant_list = ant_list->next;
	while (j < i && data->amount != 0)
	{
		if (spread[j] != 0)
		{
			ant_num++;
			spawn_helper(&j, spread, data, &ant_list);
			ant_list->ant = ant_num;
		}
		j++;
	}
	ant_list->next = NULL;
}
