/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:14:14 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/26 17:36:25 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if (number <= how many is pushed over)
// 	push over and rotate b (essentially append at bottom)
// 	count ++
// else if number is smaller than decision median (sqrt(start len) * 1.3)
// 	push to b
// 	count ++
// else 
// 	rotate

void	push_swap_sort(t_stack *stack_a, t_stack *stack_b, int decision_median)
{
	while (stack_a->count > 0)
	{
		if (stack_a->numbers[0] > stack_b->count)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else if (stack_a->numbers[0] < decision_median)
		{
			push_b(stack_a, stack_b);
		}
		else
		{
			rotate_a(stack_a);
		}
	}
}
