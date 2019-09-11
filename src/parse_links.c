/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 13:38:04 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/11 13:56:15 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static t_hash_graph	*find_node(t_lem_in *data, char *key)
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

static void			add_neighbour(t_hash_graph *node1, t_hash_graph *node2)
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

static void			connect_nodes(char *key1, char *key2, t_lem_in *data)
{
	t_hash_graph	*node1;
	t_hash_graph	*node2;

	node1 = find_node(data, key1);
	node2 = find_node(data, key2);
	if (node1 == NULL || node2 == NULL)
		return ;
	add_neighbour(node1, node2);
}

void				get_edge(char *line, t_lem_in *data)
{
	int				i;
	char			*key1;
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
