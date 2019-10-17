/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 19:50:41 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 15:23:30 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			print_lst_rev(t_str_lst *lst)
{
	if (lst == NULL)
		return ;
	else
		print_lst_rev(lst->next);
	ft_putendl(lst->content);
}

int				*calc_ant_spread(t_lem_in *data, int i)
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

static void		free_ant(t_ant **ant_list, t_ant *prev, t_ant **start)
{
	if (*ant_list == *start)
	{
		*start = (*ant_list)->next;
		free(*ant_list);
	}
	else
	{
		prev->next = (*ant_list)->next;
		free(*ant_list);
	}
}

static t_ant	*move_ants(t_ant *ant_list)
{
	t_ant	*start;
	t_ant	*prev;

	start = ant_list;
	while (ant_list != NULL)
	{
		ant_list->room++;
		ft_printf("L%i-", ant_list->ant);
		ft_putstr(ant_list->room[0]->key);
		if (ant_list->room[0]->type == 2)
			free_ant(&ant_list, prev, &start);
		else
			prev = ant_list;
		ant_list = ant_list->next;
		if (ant_list != NULL)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (start);
}

void			print_solution(t_lem_in *data)
{
	int		*spread;
	int		i;
	t_ant	*ant_list;

	print_lst_rev(data->input);
	ft_putendl("");
	i = 0;
	ant_list = NULL;
	while (data->solution[i] != NULL)
		i++;
	spread = calc_ant_spread(data, i);
	while (data->amount != 0)
	{
		if (ant_list == NULL)
		{
			ant_list = (t_ant*)ft_memalloc(sizeof(t_ant));
			ant_list->next = NULL;
		}
		spawn_ants(ant_list, spread, i, data);
		ant_list = move_ants(ant_list);
	}
	while (ant_list != NULL)
		ant_list = move_ants(ant_list);
	free(spread);
}
