/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/19 15:13:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/23 15:30:22 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct		s_str_lst
{
	char				*content;
	struct s_str_lst	*next;
}					t_str_lst;

typedef struct		s_hash_graph
{
	char				*key;
	int					type;
	struct s_hash_graph	*neighbours;
	struct s_hash_graph	*coll;
}					t_hash_graph;

typedef struct		s_lem_in_lst
{
	char				*name;
	int					type;
	struct s_lem_in_lst	*next;
}					t_lem_in_lst;

typedef struct		s_lem_in
{
	int				amount;
	int				set_start;
	int				set_end;
	int				nodes;
	int				edges;
	int				hashsize;
	t_str_lst		*input;
	t_lem_in_lst	*node_lst;
	t_hash_graph	*graph;
}					t_lem_in;

int			ft_isprime(int n)
{
	int i;

	i = 2;
	if (n == 1 || n == 0)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int			get_next_prime(int n)
{
	while (n % 2 == 0)
		n++;
	while (!ft_isprime(n))
		n++;
	return (n);
}

int			ft_hash(char *key, int size)
{
	int index;
	int i;

	i = 0;
	index = 0;
	if (key == NULL)
		return (-1);
	while (key[i] != '\0')
	{
		index = index + key[i] * (i + 1);
		i++;
	}
	index = ft_abs(index);
	return (index % size);
}

void	print_lst_rev(t_str_lst *current)
{
	if (current == NULL)
		return;
	else
		print_lst_rev(current->next);
	ft_putendl(current->content);
}

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
	t_str_lst	*current;

	if (current == NULL)
	{
		current = (t_str_lst*)malloc(sizeof(t_str_lst));
		current->next = NULL;
		data->input = current;
	}
	else
	{
		current = (t_str_lst*)malloc(sizeof(t_str_lst));
		current->next = data->input;
		data->input = current;
	}
	current->content = ft_strdup(line);
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
	if (current == NULL)
	{
		current = (t_lem_in_lst*)malloc(sizeof(t_lem_in_lst));
		current->next = NULL;
		data->node_lst = current;
	}
	else
	{
		current = (t_lem_in_lst*)malloc(sizeof(t_lem_in_lst));
		current->next = data->node_lst;
		data->node_lst = current;
	}
	current->name = ft_getword(line, 1);
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

void	build_graph(t_lem_in *data)
{
	int				index;
	t_lem_in_lst	*current;
	t_hash_graph	*node;

	data->hashsize = get_next_prime(data->nodes);
	data->graph = (t_hash_graph*)malloc(sizeof(t_hash_graph) * data->hashsize);
	current = data->node_lst;
	while (current != NULL)
	{
		index = ft_hash(current->name, data->hashsize);
		node = &(data->graph[index]);
		if (node->key != NULL)
		{
			while (node->coll != NULL)
				node = node->coll;
			node->coll = (t_hash_graph*)malloc(sizeof(t_hash_graph));
			node = node->coll;
		}
		node->key = current->name;
		node->type = current->type;

		ft_putnbr(index);
		write(1, "\n", 1);
		ft_putendl(node->key);
		write(1, "\n", 1);

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
	build_graph(&data);
	// check_data(&data);
	check_parsing(&data);
	print_lst_rev(data.input);
	
//	test
	linenum = ft_hash("4", data.hashsize);
	ft_putnbr(linenum);
	ft_putendl(data.graph[linenum].key);

	return (0);
}
