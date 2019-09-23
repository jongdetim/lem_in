/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:28:53 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/23 18:12:13 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

# define PATH_NUMS 5000
# define PATH_LEN 100
# define HTABLE_SIZE 64
# define MAX_VISITS 24

typedef struct		s_pathing_params
{
	int					n;
	int					i;
	int					lowest;
	struct s_neighbours	*save;
	struct s_neighbours	*mem[5];
	struct s_neighbours	*nb;
}					t_pathing_params;

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
	int					visited;
	int					level;
	int					conn;
	t_neighbours		*neighbours;
	struct s_hash_graph	*coll;
}					t_hash_graph;

typedef struct		s_path_queue
{
	t_hash_graph		**path;
	struct s_path_queue	*next;
}					t_path_queue;

typedef struct		s_bfs_queue
{
	t_hash_graph		*node;
	struct s_bfs_queue	*next;
}					t_bfs_queue;

typedef struct		s_lem_in_lst
{
	char				*name;
	int					type;
	struct s_lem_in_lst	*next;
}					t_lem_in_lst;

typedef struct		s_combos
{
	t_hash_graph		***combo;
	struct s_combos		*next;
}					t_combos;

typedef struct		s_ant
{
	struct s_ant		*next;
	int					ant;
	t_hash_graph		**room;
}					t_ant;

typedef struct		s_lem_in
{
	int					amount;
	int					set_start;
	int					set_end;
	int					nodes;
	int					edges;
	int					hashsize;
	int					collisions;
	int					path_num;
	int					combo_max;
	long				path_amount;
	t_path_queue		*end_of_queue;
	t_bfs_queue			*end_of_bfs_queue;
	t_str_lst			*input;
	t_lem_in_lst		*node_lst;
	t_hash_graph		*graph;
	t_hash_graph		*start;
	t_hash_graph		*end;
	t_hash_graph		***paths;
	t_hash_graph		***complete;
	t_combos			*combo_lst;
	t_hash_graph		***solution;
	int					solution_steps;
}					t_lem_in;

/*
**	main.c
*/
void				add_list(char *line, t_lem_in *data);

/*
**	validate_format.c
*/
int					ft_validate_format(char *format, char *str);

/*
**	input_check.c
*/
void				check_comment(char *str, t_lem_in *data);
void				validate_ants(t_lem_in *data);

/*
**	get_rooms.c
*/
int					create_rooms(t_lem_in *data, char *line);

/*
**	build_graph.c
*/
void				build_graph(t_lem_in *data);

/*
**	connect_graph.c
*/
void				read_edge(char *line, t_lem_in *data);

/*
**	bfs.c
*/
void				bfs(t_lem_in *data);

/*
**	trim_graph.c
*/
void				trim_graph(t_hash_graph *node);

/*
**	pathing.c
*/
void				find_paths(t_lem_in *data);

/*
**	combos.c
*/
void				choose_combos(t_lem_in *data);

/*
**	combos_helper.c
*/
void				combo_helper(int j, t_lem_in *data, int *arr);
float				calculate_steps(t_lem_in *data, int *arr);

/*
**	spawn_ants.c
*/
void				spawn_ants(t_ant *ant_list, int *spread,
										int i, t_lem_in *data);

/*
**	print.c
*/
void				print_solution(t_lem_in *data);
void				print_lst_rev(t_str_lst *lst);

#endif
