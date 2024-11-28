/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:53:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 23:13:40 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a function for `normalize_numbers`
int	*normalize_numbers(long *temp_array, int arr_len)
{
	int		index;
	int		*new_array;
	long	current_smallest_index;

	new_array = malloc(sizeof(int) * arr_len);
	if (new_array == NULL)
		return (NULL);
	index = 0;
	current_smallest_index = -1;
	while (index < arr_len)
	{
		current_smallest_index = get_next_smallest_index(temp_array,
				current_smallest_index, arr_len);
		if (current_smallest_index == -1)
		{
			return (free(new_array), NULL);
		}
		new_array[current_smallest_index] = index + 1;
		index++;
	}
	return (new_array);
}

t_stack	*initialize_stack(char **numbers_as_strings, int skip)
{
	int		str_arr_len;
	t_stack	*stack;
	long	*temp_array;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	str_arr_len = 0;
	while (numbers_as_strings[str_arr_len] != NULL)
		str_arr_len++;
	temp_array = create_temp_array(numbers_as_strings, skip, str_arr_len);
	if (temp_array == NULL)
		return (free(stack), NULL);
	stack->numbers = normalize_numbers(temp_array, str_arr_len - skip);
	if (stack->numbers == NULL)
		return (free(temp_array), free(stack), NULL);
	free(temp_array);
	stack->count = str_arr_len - skip;
	stack->max_count = str_arr_len - skip;
	stack->stack_name = 'a';
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
	stack->stack_name = 'b';
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
