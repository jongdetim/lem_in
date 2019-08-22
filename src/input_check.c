/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:06:47 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/22 15:37:02 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		validate_ants(t_lem_in *data)
{
	char	*str;
	int		ants;

	while (get_next_line(0, &str))
	{
		add_list(str, data);
		if (str[0] != '#')
			break ;
	}
	if (!ft_validate_format("%d", str) || str[0] == '-')
			ft_error("Input of ants is invalid! :(");
	ants = ft_atoi(str);
	if (ants == 0)
		ft_error("Ants can't be zero! :(");
	// ft_printf("number of ants right now: %s\n", str);
	return (ants);
}

char	*check_comment(char *str, t_lem_in *data)
{
	if (*(str + 1) == '#')
	{
		if (!ft_strcmp(str, "##end") && data->set_end == 0)
			data->set_end = 1;
		else if (!ft_strcmp(str, "##start") && data->set_start == 0)
			data->set_start = 1;
	}
	add_list(str, data);
	if ((data->set_end == 1 || data->set_start == 1) && ft_validate_format("%s %d %d", str))
		ft_error("Start or End has no room assigned!");
	return (str);
}

void	check_room(char *str, t_lem_in *data)
{
	
	if (str[0] == 'L')
		ft_error("Room names can't start with an L");
	get_node(str, data);
	add_list(str, data);
}

int		create_rooms(t_lem_in *data, char *line)
{
	if (line[0] == '#')
		line = check_comment(line, data);
	else if (ft_validate_format("%s %d %d", line))
		check_room(line, data);
	else if (ft_validate_format("%s-%s", line))
		return (0) ;
	else
		ft_error("Something went wrong with the parsing of rooms or links");
	ft_strdel(&line);
	return (1);
}
