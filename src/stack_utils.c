/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:30:49 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 15:32:00 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a function for `create_temp_array`
long	*create_temp_array(char **numbers_as_strings, int skip, int str_arr_len)
{
	int		index;
	long	*temp_array;

	temp_array = malloc(sizeof(long) * (str_arr_len - skip));
	if (temp_array == NULL)
		return (NULL);
	index = 0;
	while (numbers_as_strings[index + skip] != NULL)
	{
		if (ft_isdigit_str(numbers_as_strings[index + skip]) == 0)
			return (free(temp_array), NULL);
		temp_array[index] = ft_atoi(numbers_as_strings[index + skip]);
		index++;
	}
	return (temp_array);
}

int	get_smallest_index(long *arr, int arr_len)
{
	int		index;
	long	current_smallest;
	int		current_smallest_index;

	current_smallest = __LONG_MAX__;
	current_smallest_index = -1;
	index = 0;
	while (index < arr_len)
	{
		if (arr[index] <= current_smallest)
		{
			current_smallest = arr[index];
			current_smallest_index = index;
		}
		index++;
	}
	return (current_smallest_index);
}

int	get_index_distance(int index_1, int index_2)
{
	int	distance;

	distance = index_1 - index_2;
	if (distance < 0)
		return (distance * -1);
	return (distance);
}

int	get_next_smallest_index(long *temp_array,
	int current_smallest_index, int arr_len)
{
	int	index;
	int	next_smallest_index;
	int	distance;
	int	new_distance;

	index = 0;
	distance = -1;
	next_smallest_index = -1;
	if (current_smallest_index == -1)
		return (get_smallest_index(temp_array, arr_len));
	while (index < arr_len)
	{
		if (temp_array[index] > temp_array[current_smallest_index])
		{
			new_distance = get_index_distance(temp_array[index],
					temp_array[current_smallest_index]);
			if (new_distance < distance || distance == -1)
			{
				distance = new_distance;
				next_smallest_index = index;
			}
		}
		index++;
	}
	return (next_smallest_index);
}
