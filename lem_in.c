/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/19 15:13:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/19 19:44:19 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct	s_lem_in_lst
{
	char				*name;
	int					type;
	struct s_lem_in_lst	*next;
}				t_lem_in_lst;


typedef struct	s_lem_in
{
	int				amount;
	int				set_start;
	int				set_end;
	int				nodes;
	int				edges;
	t_lem_in_lst	*node_lst;
}				t_lem_in;

int		check_edge(char *line)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (ft_iswhitespace(line[i]) == 1)
			return (0);
		if (line[i] == '-')
			count++;;
		i++;
	}
	if (count == 1 && i > 2)
		return (1);
	else
		return (0);
}

int		check_node(char *line)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			count++;
		else if (count > 0 && (line[i] < '0' || line[i] > '9'))
			return (0);
		i++;
	}
	if (count == 2 && i > 4)
		return (1);
	else
		return (0);
}

void	add_list(char *line, t_lem_in *data)
{
	//volledige input opslaan zodat dit uiteindelijk geprint kan worden op stdout
}

void	deal_hash(char *line, t_lem_in *data)
{
	if (line[1] == '#')
	{
		if (ft_strcmp(line + 2, "start") == 0)
			data->set_start = 1;
		else if (ft_strcmp(line + 2, "end") == 0)
			data->set_end = 1;
	}
}

char	*ft_getword(char *str, int n)
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

void	set_startend(t_lem_in_lst *node, t_lem_in *data)
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

void	get_node(char *line, t_lem_in *data)
{
	t_lem_in_lst	*current;

	data->nodes++;
	current = data->node_lst;
	if (current == NULL)
	{
		current = (t_lem_in_lst*)malloc(sizeof(t_lem_in_lst));
		data->node_lst = current;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = (t_lem_in_lst*)malloc(sizeof(t_lem_in_lst));
		current = current->next;
	}
	current->name = ft_getword(line, 1);
	current->next = NULL;
	current->type = 0;
	set_startend(current, data);
}

void	get_edge(char *line, t_lem_in *data)
{
	
}

void	init_lem_in(t_lem_in *data)
{
	data->nodes = 0;
	data->edges = 0;
	data->set_end = 0;
	data->set_start = 0;
	data->node_lst = NULL;
}

void	check_parsing(t_lem_in *data)
{
	t_lem_in_lst	*current;

	current = data->node_lst;
	ft_printf("%d ants\n%d nodes\n", data->amount, data->nodes);
	while (current != NULL)
	{
		if (current->type == 1)
			ft_printf("%s is beginning\n", current->name);
		if (current->type == 2)
			ft_printf("%s is end\n", current->name);
		current = current->next;
	}
}

int		main(void)
{
	char		*line;
	int			linenum;
	t_lem_in	data;

	init_lem_in(&data);
	linenum = 0;
	while (get_next_line(0, &line) == 1)
	{
		linenum++;
		if (linenum == 1)
			data.amount = ft_atoi(line);
		else if (line[0] == '#')
			deal_hash(line, &data);
		else if (check_node(line) == 1)
			get_node(line, &data);
		else if (check_edge(line) == 1)
			get_edge(line, &data);
		else
			break ;
		add_list(line, &data);
		free(line);
	}
	// check_data(&data);
	check_parsing(&data);
	return (0);
}
