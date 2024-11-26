/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:18:41 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/26 16:54:38 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of a and put it at the top of b. 
void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	shift_forward(stack_b);
	stack_b->numbers[0] = stack_a->numbers[0];
	stack_b->count++;
	shift_backward(stack_a);
	stack_a->count--;
	ft_printf("pb\n");
}
