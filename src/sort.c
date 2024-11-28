/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:14:14 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 15:48:29 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_biggest_number_index(t_stack *stack)
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

static void	back_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	biggest_index;

	while (stack_b->count > 0)
	{
		biggest_index = get_biggest_number_index(stack_b);
		if (biggest_index < stack_b->count / 2)
		{
			while (biggest_index > 0)
			{
				rotate_b(stack_b);
				biggest_index--;
			}
		}
		else
		{
			while (biggest_index < stack_b->count)
			{
				reverse_rotate_b(stack_b);
				biggest_index++;
			}
		}
		push_a(stack_a, stack_b);
	}
}

void	push_swap_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	decision_median;

	decision_median = (double)ft_sqrt(stack_a->count) * (double) 1.3;
	if (stack_sorted(stack_a))
		return ;
	while (stack_a->count > 0)
	{
		if (stack_a->numbers[0] <= stack_b->count)
		{
			push_b(stack_a, stack_b);
			if (!(stack_a->numbers[0] <= stack_b->count + decision_median))
				rotate_ab(stack_a, stack_b);
			else
				rotate_b(stack_b);
		}
		else if (stack_a->numbers[0] <= stack_b->count + decision_median)
		{
			push_b(stack_a, stack_b);
		}
		else if (stack_a->count > 1)
			rotate_a(stack_a);
	}
	back_to_stack_a(stack_a, stack_b);
}
