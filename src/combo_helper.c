/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combo_helper.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 20:15:04 by tide-jon       #+#    #+#                */
/*   Updated: 2019/09/16 20:27:33 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

float			calculate_steps(t_lem_in *data, int *arr)
{
	int		k;
	int		l;
	int		nodes;
	int		paths;
	float	steps;

	k = 0;
	paths = 0;
	nodes = 0;
	while (k < data->combo_max && arr[k] != -1)
	{
		l = 0;
		while (data->complete[arr[k]][l + 2] != NULL && l < PATH_LEN - 2)
			l++;
		nodes += l;
		paths++;
		k++;
	}
	steps = (float)(data->amount + nodes) / (float)paths;
	return (steps);
}

static int		check_improvement(int j, t_lem_in *data, int *arr)
{
	float	steps;
	int		k;

	k = 0;
	steps = calculate_steps(data, arr);
	while (arr[k] != -1)
		k++;
	arr[k] = j;
	if (calculate_steps(data, arr) < steps)
		return (1);
	arr[k] = -1;
	return (0);
}

static int		check_overlap(int j, int m, t_lem_in *data, int *arr)
{
	int	k;
	int l;

	while (data->complete[j][m + 1] != NULL && m < PATH_LEN - 1)
	{
		k = 0;
		if (data->complete[j][m]->conn > 2)
		{
			while (data->complete[arr[k]] != NULL && arr[k] != j)
			{
				l = 1;
				while (data->complete[arr[k]][l + 1] != NULL &&
												l < PATH_LEN - 1)
				{
					if (data->complete[arr[k]][l]->conn > 2 &&
					data->complete[arr[k]][l] == data->complete[j][m])
						return (0);
					l++;
				}
				k++;
			}
		}
		m++;
	}
	return (1);
}

void			combo_helper(int j, t_lem_in *data, int *arr)
{
	int k;
	int	m;

	k = 0;
	m = 1;
	if (check_improvement(j, data, arr) == 1)
	{
		if (check_overlap(j, m, data, arr) != 1)
		{
			while (arr[k] != j)
				k++;
			arr[k] = -1;
		}
	}
}
