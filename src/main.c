/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:14:05 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/30 15:33:20 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*read_with_split_input(char *input_str)
{
	char	**split_input;
	t_stack	*stack_a;
	int		index;

	split_input = ft_split(input_str, ' ');
	if (split_input == NULL)
		return (NULL);
	stack_a = initialize_stack(split_input, 0);
	index = 0;
	while (split_input[index] != NULL)
	{
		free(split_input[index]);
		index++;
	}
	free(split_input);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		stack_a = read_with_split_input(argv[1]);
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
	push_swap_sort(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
