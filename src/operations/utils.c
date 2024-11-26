/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:53:08 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/26 16:53:27 by rreimann         ###   ########.fr       */
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
		stack->numbers[index]  = stack->numbers[index + 1];
		index++;
	}
}