/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:14:14 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/26 17:10:29 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	rotate_b(stack_b);
}