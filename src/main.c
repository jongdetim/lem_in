/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 13:38:22 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/11 13:57:28 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			ft_error(char str[100])
{
	ft_printf("%s\n", str);
	exit(0);
}

static void		init_lem_in(t_lem_in *data)
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
}

int				read_edge(char *line, t_lem_in *data)
{
	if (line && line[0] == '#')
		line = check_comment(line, data);
	else if (line && ft_validate_format("%s %d %d", line))
		ft_error("Wrong order or rooms/links");
	else if (line && !ft_validate_format("%s-%s", line))
		ft_error("That link format is not valid!");
	else
		get_edge(line, data);
	ft_strdel(&line);
	return (1);
}

int				main(void)
{
	char		*line;
	t_lem_in	data;

	init_lem_in(&data);
	validate_ants(&data);
	while (get_next_line(0, &line))
	{
		if (create_rooms(&data, line) == 0)
			break ;
	}
	build_graph(&data);
	read_edge(line, &data);
	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
			line = check_comment(line, &data);
		if (read_edge(line, &data) == 0)
			break ;
	}
	bfs(&data);
	find_paths(&data);
	choose_combos(&data);
	print_solution(&data);
	return (0);
}
