/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_smallest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:28:59 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 23:16:50 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_number_index(t_stack *stack)
{
	int	index;
	int	max_value;
	int	max_value_index;

	index = 0;
	max_value = 0;
	while (index < stack->count)
	{
		if (stack->numbers[index] > max_value)
		{
			max_value = stack->numbers[index];
			max_value_index = index;
		}
		index++;
	}
	return (max_value_index);
}

int	get_smallest_number_index(t_stack *stack)
{
	int	index;
	int	smallest_number;
	int	smallest_index;

	index = 0;
	smallest_number = stack->numbers[index];
	smallest_index = index;
	while (index < stack->count)
	{
		if (stack->numbers[index] < smallest_number)
		{
			smallest_index = index;
			smallest_number = stack->numbers[index];
		}
		index++;
	}
	return (smallest_index);
}
