/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:14:14 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 22:30:35 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	back_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	biggest_index;

	while (stack_b->count > 0)
	{
		biggest_index = get_biggest_number_index(stack_b);
		bring_index_to_top(stack_b, biggest_index);
		push_a(stack_a, stack_b);
	}
}

void	push_swap_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	decision_median;

	if (stack_sorted(stack_a))
		return ;
	if (stack_a->count <= 5)
		return (sort_up_to_five_values(stack_a, stack_b));
	decision_median = (double)ft_sqrt(stack_a->count) * (double) 1.3;
	while (stack_a->count > 0)
	{
		if (stack_a->numbers[0] <= stack_b->count)
		{
			push_b(stack_a, stack_b);
			if (!(stack_a->numbers[0] <= stack_b->count + decision_median))
				rotate_ab(stack_a, stack_b);
			else
				rotate_print(stack_b);
		}
		else if (stack_a->numbers[0] <= stack_b->count + decision_median)
			push_b(stack_a, stack_b);
		else if (stack_a->count > 1)
			rotate_print(stack_a);
	}
	back_to_stack_a(stack_a, stack_b);
}
