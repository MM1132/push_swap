/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:53:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/26 16:24:54 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack(char **numbers_as_strings, int skip)
{
	int		index;
	t_stack	*stack;

	stack = malloc(sizeof(stack));
	if (stack == NULL)
		return (NULL);
	index = 0;
	while (numbers_as_strings[index] != NULL)
		index++;
	stack->numbers = malloc(sizeof(int) * (index + 1 - skip));
	if (stack->numbers == NULL)
		return (free(stack), NULL);
	stack->count = index - skip;
	stack->max_count = index - skip;
	index = 0;
	while (numbers_as_strings[index + skip] != NULL)
	{
		stack->numbers[index] = ft_atoi(numbers_as_strings[index + skip]);
		index++;
	}
	stack->numbers[index] = 0;
	return (stack);
}

t_stack	*initialize_stack_empty(int length)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->numbers = malloc(sizeof(int) * (length + 1));
	if (stack->numbers == NULL)
		return (free(stack), NULL);
	stack->count = 0;
	stack->max_count = length;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;

	free(stack->numbers);
	free(stack);
}

void	print_stack(t_stack *stack)
{
	int	index;

	ft_printf("Stack numbers: ");
	index = 0;
	while (index < stack->count)
	{
		ft_printf("%d ", stack->numbers[index]);
		index++;
	}
	ft_printf("\nCount: %d\n", stack->count);
}
