/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:04:17 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/14 18:34:31 by awehlbur      ########   odam.nl         */
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

int		main(void)
{
	char		*line;
	int			linenum;
	t_lem_in	data;

	data.collisions = 0;
	init_lem_in(&data);
	linenum = 0;
	data.amount = validate_ants(&data);
	create_rooms(&data, 0);
	while (get_next_line(0, &line))
	{
		while (line && line[0] == '#')
			line = check_comment(line, &data);
		if (line && ft_validate_format("%s %d %d", line))
			ft_error("Wrong order or rooms/links");
		if (line && ft_validate_format("%s-%s", line))
			get_edge(line, &data);
		else
			break ;
		ft_strdel(&line);
	}
	build_graph(&data);


		int *nums;

	nums = (int*)ft_memalloc(sizeof(int) * data.hashsize);
	ft_memset(nums, 0, data.hashsize);
	while (data.node_lst != NULL)
	{
		// ft_putnbr(ft_hash_str(data.node_lst->name, data.hashsize));
		// write(1, "\n", 1);
		nums[ft_hash_str(data.node_lst->name, data.hashsize)]++;
		data.node_lst = data.node_lst->next;
	}

	int x = 0;

	while (x < data.hashsize)
	{
		ft_putnbr(nums[x]);
		write(1, "\n", 1);
		x++;
	}

	// ft_printf("%f%% of collisions", ((float)data.collisions / (float)data.hashsize) * 100);
	return (0);
}