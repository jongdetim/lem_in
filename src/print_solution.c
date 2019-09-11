/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_solution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 14:04:49 by anonymous      #+#    #+#                */
/*   Updated: 2019/09/04 16:29:25 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			print_lst_rev(t_str_lst *curr)
{
	if (curr == NULL)
		return;
	else
		print_lst_rev(curr->next);
	ft_putendl(curr->content);
}

void			print_init(t_lem_in *data, t_print_list *ptr)
{
	int				store;
	t_print_list	*temp;

	store = 0;
	temp = ptr;
	ft_putstr("\n");
	data->path_amount = 0;
	while (data->solution[data->path_amount] != NULL)
		data->path_amount++;
	while (store < data->amount)
	{
		temp->nnb = 1;
		temp->finished = 0;
		temp->pnb = store % data->path_amount;
		temp->ant = store;
		temp->room = data->solution[0][0]->key;
		temp->next = (t_print_list*)malloc(sizeof(t_print_list));
		temp = temp->next;
		store++;
	}
	temp->next = NULL;
}

static int		check_finished(t_print_list *start)
{
	t_print_list		*curr;

	curr = start;
	while (curr != NULL)
	{
		if (curr->finished == 0)
			return (0);
		curr = curr->next;
	}
	return (0);
}

static void		actual_printing(t_lem_in *data, t_print_list *curr)
{
	ft_putstr("L");
	ft_putnbr(curr->ant + 1);
	ft_putstr("-");
	ft_putstr(data->solution[curr->pnb][curr->nnb]->key);
	ft_putstr(" ");
	if (data->solution[curr->pnb][curr->nnb]->type == 2)	
		curr->finished = 1;
	data->solution[curr->pnb][curr->nnb]->empty = 0;
	if (data->solution[curr->pnb][curr->nnb]->type != 2)
		curr->nnb++;
	if (data->solution[curr->pnb][curr->nnb]->type != 2)
		data->solution[curr->pnb][curr->nnb]->empty = 1;
}

void			print_ants(t_lem_in *data, t_print_list *ptr_start)
{
	t_print_list 	*curr;
	int				i;
	int				counter;

	i = 0;
	counter = 0;
	while (i < data->solution_steps)
	{
		curr = ptr_start;
		while (curr != NULL)
		{
			if ((data->solution[curr->pnb][curr->nnb]->type == 0 || \
			data->solution[curr->pnb][curr->nnb]->type == 2) \
			&& curr->finished != 1)
			{
				if (data->solution[curr->pnb][curr->nnb]->type == 2)
					actual_printing(data, curr);
				else if (data->solution[curr->pnb][curr->nnb + 1]->empty == 0)
					actual_printing(data, curr);
			}
			if (check_finished(ptr_start) == 1)
				return ;
			curr = curr->next;
		}
		ft_putstr("\n");
		counter++;
		i++;
	}
}