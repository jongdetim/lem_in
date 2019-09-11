/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_hash.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/19 15:13:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/11 13:46:37 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			add_list(char *line, t_lem_in *data)
{
	t_str_lst	*current;

	current = (t_str_lst*)malloc(sizeof(t_str_lst));
	current->next = data->input;
	data->input = current;
	current->content = ft_strdup(line);
}

void			deal_hash(char *line, t_lem_in *data)
{
	if (line[1] == '#')
	{
		if (ft_strcmp(line + 2, "start") == 0)
			data->set_start = 1;
		else if (ft_strcmp(line + 2, "end") == 0)
			data->set_end = 1;
	}
}

static char		*ft_getword(char *str)
{
	int i;
	int start;

	i = 0;
	while (str[i] != '\0' && ft_iswhitespace(str[i]) == 1)
		i++;
	start = i;
	while (str[i] != '\0' && ft_iswhitespace(str[i]) != 1)
		i++;
	return (ft_strsub(str, start, i - start));
}

static void		set_startend(t_lem_in_lst *node, t_lem_in *data)
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

void			get_node(char *line, t_lem_in *data)
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
	current->name = ft_getword(line);
	current->type = 0;
	set_startend(current, data);
	data->node_lst = current;
}
