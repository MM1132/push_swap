/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:03:22 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 21:20:33 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int	last_number_save;

	last_number_save = stack->numbers[stack->count - 1];
	shift_forward(stack);
	stack->numbers[0] = last_number_save;
}

void	reverse_rotate_print(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rr%c\n", stack->stack_name);
}
