/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:28:53 by awehlbur       #+#    #+#                */
/*   Updated: 2019/08/15 13:09:37 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
// #include <stdio.h>

typedef struct		s_str_lst
{
	char				*content;
	struct s_str_lst	*next;
}					t_str_lst;

typedef struct		s_neighbours
{
	struct s_hash_graph	*node;
	struct s_neighbours	*neighbours;
}					t_neighbours;

typedef struct		s_hash_graph
{
	char				*key;
	int					type;
	t_neighbours		*neighbours;
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
	int				collisions;
	t_str_lst		*input;
	t_lem_in_lst	*node_lst;
	t_hash_graph	*graph;
}					t_lem_in;

/*
** main.c
 */
int			main(void);
void		ft_error(char str[100]);
int			read_edge(char *line, t_lem_in *data);

/*
** validate_format.c
 */
int			ft_validate_format(char *format, char *str);

/*
** input_check.c
 */
int			create_rooms(t_lem_in *data, int flag, char *line);
void		check_room(char *str, t_lem_in *data);
char		*check_comment(char *str, t_lem_in *data);
int			validate_ants(t_lem_in *data);

/*
** lem_in.c
 */
void	build_graph(t_lem_in *data);
void	check_parsing(t_lem_in *data);
void	init_lem_in(t_lem_in *data);
void	get_edge(char *line, t_lem_in *data);
void	get_node(char *line, t_lem_in *data);
void	set_startend(t_lem_in_lst *node, t_lem_in *data);
char	*ft_getword(char *str);
void	deal_hash(char *line, t_lem_in *data);
void	add_list(char *line, t_lem_in *data);
int		check_node(char *line);
int		check_edge(char *line);
void	print_lst_rev(t_str_lst *current);
int			ft_hash_str(char *key, int size);
int			get_next_prime(int n);
int			ft_isprime(int n);
void	get_edge(char *line, t_lem_in *data);
void	connect_nodes(char *key1, char *key2, t_lem_in *data);
void	add_neighbour(t_hash_graph *node1, t_hash_graph *node2);
t_hash_graph	*find_node(t_lem_in *data, char *key);


#endif