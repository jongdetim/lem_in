#include "../lem_in.h"



void	find_paths(t_hash_graph *graph, t_lem_in *data)
{
	t_hash_graph *current;
	t_neighbours *neighbours;

	current = data->startnode;
	
	while ()
	{
		neighbours = current->neighbours;
		while (neighbours != NULL)
		{
			queue(neighbours);
			neighbours = neighbours->neighbours;
		}
}
