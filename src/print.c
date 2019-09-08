#include "../lem_in.h"

void	print_lst_rev(t_str_lst *lst)
{
	if (lst == NULL)
		return;
	else
		print_lst_rev(lst->next);
	ft_putendl(lst->content);
}

int		*calc_ant_spread(t_lem_in *data, int i)
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

void	spawn_helper(int *j, int *spread, t_lem_in *data, t_ant **ant_list)
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

void	spawn_ants(t_ant *ant_list, int *spread, int i, t_lem_in *data)
{
	static int	ant_num;
	int 		j;

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

void	free_ant(t_ant **ant_list, t_ant *prev, t_ant **start)
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

t_ant	*move_ants(t_ant *ant_list)
{
	t_ant 	*start;
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

void	print_solution(t_lem_in *data)
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
	if (ant_list == NULL)
	{
		ant_list = (t_ant*)ft_memalloc(sizeof(t_ant));
		ant_list->next = NULL;
	}
	while (data->amount != 0)
	{
		spawn_ants(ant_list, spread, i, data);
		ant_list = move_ants(ant_list);
	}
	while (ant_list != NULL)
	{
		ant_list = move_ants(ant_list);
	}
}