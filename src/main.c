/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:04:17 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/29 20:13:57 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

// nog te fixen:
// comments tussen ##start en room_start of ##end en room_end

void	ft_error(char str[100])
{
	ft_printf("%s\n", str);
	exit (0);
}

int		read_edge(char *line, t_lem_in *data)
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

int		main(void)
{
	char		*line;
	t_lem_in	data;

	close(0);
	open("./flow10", 0, O_RDONLY);

	init_lem_in(&data);
	data.amount = validate_ants(&data);
	while (get_next_line(0, &line))
	{
		if (create_rooms(&data, line) == 0)
			break ;
	}
	build_graph(&data);
	read_edge(line, &data);
	while (get_next_line(0, &line))
	{
		if (read_edge(line, &data) == 0)
			break ;
	}
	bfs(&data);
	find_paths(&data);
	choose_combos(&data);


//	PRINT SOLUTION AMOUNT OF STEPS

	// ft_putnbr(data.solution_steps);

//	PRINT SOLUTION PATH
	int i;
	int j;

	i = 0;
	while (i < PATH_NUMS && data.solution[i] != NULL)
	{
		j = 0;
		if (data.solution[i][j] != NULL)
		{
			while (j < PATH_LEN && data.solution[i][j] != NULL)
			{
				ft_putendl(data.solution[i][j]->key);
				j++;
			}
			ft_putendl("");
		}
		i++;
	}


//	PRINT PATHS
	// int i;
	// int j;

	// i = 0;
	// while (i < PATH_NUMS)
	// {
	// 	j = 0;
	// 	if (data.paths[i][j] != NULL)
	// 	{
	// 		while (j < PATH_LEN && data.paths[i][j] != NULL)
	// 		{
	// 			ft_putendl(data.paths[i][j]->key);
	// 			j++;
	// 		}
	// 		ft_putendl("");
	// 	}
	// 	i++;
	// }

//	PRINT COMPLETE PATHS
	// i = 0;
	// while (data.complete[i] != NULL)
	// 	i++;
	// ft_printf("%i complete paths found", i);

//	PRINT ALL POSSIBLE COMBINATIONS (INCLUDING OVERLAPPING)
	// int	i;
	// i = 0;
	// while (data.combo_lst != NULL)
	// {
	// 	i++;
	// 	data.combo_lst = data.combo_lst->next;
	// }
	// ft_putnbr(i);

	// ft_putendl("TO DO: combinaties checken op overlap. indien geen overlap: formule gebruiken en (laagste) waarde opslaan");

// t_hash_graph *test;
// t_neighbours *room;

// test = &data.graph[ft_hash_str("start", data.hashsize)];
// room = test->neighbours;
// while (room != NULL)
// {
// 	ft_putendl(room->node->key);
// 	room = room->neighbours;
// }
// ft_putendl("");
// test = &data.graph[ft_hash_str("4", data.hashsize)];
// room = test->neighbours;
// while (room != NULL)
// {
// 	ft_putendl(room->node->key);
// 	room = room->neighbours;
// }
// ft_putendl("");
// test = &data.graph[ft_hash_str("end", data.hashsize)];
// room = test->neighbours;
// while (room != NULL)
// {
// 	ft_putendl(room->node->key);
// 	room = room->neighbours;
// }

// 	int *nums;

// 	nums = (int*)ft_memalloc(sizeof(int) * data.hashsize);
// 	ft_memset(nums, 0, data.hashsize);
// 	while (data.node_lst != NULL)
// 	{
// 		ft_putnbr(ft_hash_str(data.node_lst->name, data.hashsize));
// 		write(1, "\n", 1);
// 		nums[ft_hash_str(data.node_lst->name, data.hashsize)]++;
// 		data.node_lst = data.node_lst->next;
// 	}

// 	int x = 0;

// 	while (x < data.hashsize)
// 	{
// 		ft_putnbr(nums[x]);
// 		write(1, "\n", 1);
// 		x++;
// 	}

// 	ft_printf("%f%% of collisions", ((float)data.collisions / (float)data.nodes) * 100);
	return (0);
}