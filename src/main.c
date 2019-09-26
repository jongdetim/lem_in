/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:04:17 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/23 18:10:07 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		add_list(char *line, t_lem_in *data)
{
	t_str_lst	*current;

	current = (t_str_lst*)malloc(sizeof(t_str_lst));
	current->next = data->input;
	data->input = current;
	current->content = ft_strdup(line);
}

static void	init_lem_in(t_lem_in *data)
{
	data->nodes = 0;
	data->edges = 0;
	data->set_end = 0;
	data->set_start = 0;
	data->node_lst = NULL;
	data->combo_max = 0;
	data->combo_lst = NULL;
	data->path_num = 0;
	data->solution = NULL;
	data->input = NULL;
	data->start = NULL;
	data->end = NULL;
	data->solution_steps = INT_MAX;
}

static void	check_start_end(t_lem_in *data)
{
	if (data->start == NULL)
		ft_error("No starting room found");
	if (data->end == NULL)
		ft_error("No end room found");
}

int			main(void)
{
	char		*line;
	t_lem_in	data;

	close(0);
	open("bigsuper2", 0, O_RDONLY);


	init_lem_in(&data);
	validate_ants(&data);
	while (get_next_line(0, &line) == 1)
	{
		if (create_rooms(&data, line) == 0)
			break ;
	}
	build_graph(&data);
	check_start_end(&data);
	read_edge(line, &data);
	while (get_next_line(0, &line) == 1)
		read_edge(line, &data);
	bfs(&data);
	find_paths(&data);
	if (data.complete[0] == NULL)
		ft_error("There is no path from start to end");
	choose_combos(&data);
	print_solution(&data);

	ft_putnbr(data.solution_steps);
	// while (1);
	return (0);
}
