/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_rooms.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 19:14:03 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/30 15:12:17 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	set_startend(t_lem_in_lst *node, t_lem_in *data)
{
	if (data->set_start == 1)
	{
		node->type = 1;
		data->set_start = 0;
	}
	if (data->set_end == 1)
	{
		node->type = 2;
		data->set_end = 0;
	}
}

static void	get_node(char *line, t_lem_in *data)
{
	t_lem_in_lst	*current;

	data->nodes++;
	if (data->node_lst == NULL)
	{
		current = (t_lem_in_lst*)malloc(sizeof(t_lem_in_lst));
		current->next = NULL;
	}
	else
	{
		current = (t_lem_in_lst*)malloc(sizeof(t_lem_in_lst));
		current->next = data->node_lst;
	}
	current->name = ft_get_first_substr(line);
	current->type = 0;
	set_startend(current, data);
	data->node_lst = current;
}

int			create_rooms(t_lem_in *data, char *line)
{
	if (line[0] == '#')
		check_comment(line, data);
	else if (ft_validate_format("%s %d %d", line))
	{
		if (line[0] == 'L')
			ft_error("Error: room names can't start with an L");
		get_node(line, data);
		add_list(line, data);
	}
	else if (ft_validate_format("%s-%s", line))
		return (0);
	else
		ft_error("Error: something went wrong with "
					"the parsing of rooms or links");
	free(line);
	return (1);
}
