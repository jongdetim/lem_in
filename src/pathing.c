#include "../lem_in.h"

void	allocate_paths(t_lem_in *data)
{
	int	i;

	i = 0;
	data->paths = (t_hash_graph***)ft_memalloc(sizeof(t_hash_graph**) * PATH_NUMS);
	while (i < PATH_NUMS)
	{
		data->paths[i] = (t_hash_graph**)ft_memalloc(sizeof(t_hash_graph*) * PATH_LEN);
		i++;
	}
}

void	find_paths(t_hash_graph *graph, t_lem_in *data)
{
	t_hash_graph *current;
	t_neighbours *neighbours;

	allocate_paths(data);
	current = data->start;
	while ()
	{
		neighbours = current->neighbours;
		while (neighbours != NULL)
		{
			queue(neighbours);
			neighbours = neighbours->neighbours;
		}
}
