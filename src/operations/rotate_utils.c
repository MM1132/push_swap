/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:37:08 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/29 13:54:15 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// First element becomes the last element of the stack
void	rotate_stack(t_stack *stack)
{
	int	first_number_save;

	first_number_save = stack->numbers[0];
	shift_backward(stack);
	stack->numbers[stack->count - 1] = first_number_save;
}

void	rotate_print(t_stack *stack)
{
	rotate_stack(stack);
	ft_printf("r%c\n", stack->stack_name);
}

void	bring_index_to_top(t_stack *stack, int index)
{
	if ((double)index < (double)stack->count / (double)2)
	{
		while (index > 0)
		{
			rotate_print(stack);
			index--;
		}
	}
	else
	{
		while (index < stack->count)
		{
			reverse_rotate_print(stack);
			index++;
		}
	}
}
