/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:53:08 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 15:34:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_forward(t_stack *stack)
{
	int	index;

	index = stack->count;
	if (stack->count == stack->max_count)
		index--;
	while (index > 0)
	{
		stack->numbers[index] = stack->numbers[index - 1];
		index--;
	}
}

void	shift_backward(t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->count - 1)
	{
		stack->numbers[index] = stack->numbers[index + 1];
		index++;
	}
}

// First element becomes the last element of the stack
void	rotate_stack(t_stack *stack)
{
	int	first_number_save;

	first_number_save = stack->numbers[0];
	shift_backward(stack);
	stack->numbers[stack->count - 1] = first_number_save;
}

void	reverse_rotate(t_stack *stack)
{
	int	last_number_save;

	last_number_save = stack->numbers[stack->count - 1];
	shift_forward(stack);
	stack->numbers[0] = last_number_save;
}
