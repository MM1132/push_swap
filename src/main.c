/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:14:05 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/27 12:26:04 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char	**split_input;
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc == 2) {
		split_input = ft_split(argv[1], ' ');
		if (split_input == NULL)
			return (write(2, "Error\n", 6), 1);
		stack_a = initialize_stack(split_input, 0);
		free(split_input);
		if (stack_a == NULL)
			return (write(2, "Error\n", 6), 1);
	}
	else if (argc >= 3)
	{
		stack_a = initialize_stack(argv, 1);
		if (stack_a == NULL)
			return (write(2, "Error\n", 6), 1);
	}
	else
		return (write(2, "Error\n", 6), 1);
	stack_b = initialize_stack_empty(stack_a->count);
	push_swap_sort(stack_a, stack_b, (int)((double)ft_sqrt(stack_a->count) * (double)1.3));
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
