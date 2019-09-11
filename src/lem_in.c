/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/19 15:13:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/04 14:09:02 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	collisions = 0;

#include "../lem_in.h"

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

int			ft_hash_str(char *key, int size)
{
	int index;
	int i;
	int key_len;

	i = 0;
	index = 0;
	if (key == NULL)
		return (-1);
	key_len = ft_strlen(key);
	while (key[i] != '\0')
	{
		index = (index) + (key[key_len - i - 1]) * ((32 ^ i) + (index) * (i ^ 7));
		i++;
	}
	index = ft_abs(index);
	return (index % size);
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

	current = (t_str_lst*)malloc(sizeof(t_str_lst));
	current->next = data->input;
	data->input = current;
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

char	*ft_getword(char *str)
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

void    get_node(char *line, t_lem_in *data)
{
    t_lem_in_lst    *current;

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

t_hash_graph	*find_node(t_lem_in *data, char *key)
{
	int				index;
	t_hash_graph	*node;

	index = ft_hash_str(key, data->hashsize);
	node = &(data->graph[index]);
	if (node == NULL)
		return (NULL);
	while (ft_strcmp(node->key, key) != 0)
	{
		node = node->coll;
		if (node == NULL)
			return (NULL);
	}
	return (node);
}

void	add_neighbour(t_hash_graph *node1, t_hash_graph *node2)
{
	t_neighbours	*temp;

	temp = node1->neighbours;
	node1->neighbours = (t_neighbours*)malloc(sizeof(t_neighbours));
	node1->neighbours->node = node2;
	node1->neighbours->neighbours = temp;
	temp = node2->neighbours;
	node2->neighbours = (t_neighbours*)malloc(sizeof(t_neighbours));
	node2->neighbours->node = node1;
	node2->neighbours->neighbours = temp;
}

void	connect_nodes(char *key1, char *key2, t_lem_in *data)
{
	t_hash_graph	*node1;
	t_hash_graph	*node2;

	node1 = find_node(data, key1);
	node2 = find_node(data, key2);
	if (node1 == NULL || node2 == NULL)
		return;
	add_neighbour(node1, node2);
}

void	get_edge(char *line, t_lem_in *data)
{
	int				i;
	char 			*key1;
	char			*key2;

	i = 0;
	add_list(line, data);
	while (line[i] != '-')
		i++;
	key1 = ft_strsub(line, 0, i);
	i++;
	key2 = ft_strsub(line, i, ft_strlen(line) - i);
	connect_nodes(key1, key2, data);
	free(key1);
	free(key2);
}

void	init_lem_in(t_lem_in *data)
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
}

void	get_node_type(t_hash_graph *node, t_lem_in_lst *current, t_lem_in *data)
{
	node->type = current->type;
	if (node->type == 1)
		data->start = node;
	if (node->type == 2)
		data->end = node;
}

void	build_graph(t_lem_in *data)
{
	int				index;
	t_lem_in_lst	*current;
	t_hash_graph	*node;

	data->hashsize = get_next_prime(data->nodes * 64);		//	<-- amount of collisions depends on this value
	data->graph = (t_hash_graph*)ft_memalloc(sizeof(t_hash_graph) * data->hashsize);
	current = data->node_lst;
	while (current != NULL)
	{
		index = ft_hash_str(current->name, data->hashsize);
		node = &(data->graph[index]);
		if (node->key != NULL)
		{
			data->collisions++;								// <-- debugging line
			while (node->coll != NULL)
				node = node->coll;
			node->coll = (t_hash_graph*)ft_memalloc(sizeof(t_hash_graph));
			node = node->coll;
		}
		node->key = current->name;
		get_node_type(node, current, data);
		node->coll = NULL;
		current = current->next;
	}
}
