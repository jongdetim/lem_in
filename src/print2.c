/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 13:37:53 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/11 13:55:31 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			*calc_ant_spread(t_lem_in *data, int i)
{
	int	*spread;
	int	j;

	spread = (int*)ft_memalloc(sizeof(int) * i + 1);
	spread[i] = 0;
	i = 0;
	while (data->solution[i] != NULL)
	{
		j = 0;
		while (data->solution[i][j] != NULL)
			j++;
		spread[i] = data->solution_steps - j + 2;
		i++;
	}
	return (spread);
}

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
