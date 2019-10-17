/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:06:47 by awehlbur       #+#    #+#                */
/*   Updated: 2019/10/17 15:28:57 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	validate_ants(t_lem_in *data)
{
	char	*str;
	int		ret;

	while (1)
	{
		ret = get_next_line(0, &str);
		if (ret == -1)
			ft_error("Error: cannot read file");
		if (ret == 0)
			ft_error("Error: file is empty or literally just comments");
		add_list(str, data);
		if (str[0] != '#')
			break ;
		free(str);
	}
	if (!ft_validate_format("%d", str) || str[0] == '-')
		ft_error("Error: input of ants is invalid");
	data->amount = ft_atoi(str);
	free(str);
	if (data->amount == 0)
		ft_error("Error: zero ants");
	if (data->amount < 0)
		ft_error("Error: ants can't be more than 2.147.483.647! Are you okay?");
}

void	check_comment(char *str, t_lem_in *data)
{
	if (*(str + 1) == '#')
	{
		if (!ft_strcmp(str, "##end") && data->set_end == 0)
			data->set_end = 1;
		else if (!ft_strcmp(str, "##start") && data->set_start == 0)
			data->set_start = 1;
	}
	add_list(str, data);
	if ((data->set_end == 1 || data->set_start == 1) &&
					ft_validate_format("%s %d %d", str))
		ft_error("Error: Start or End has no room assigned");
}
