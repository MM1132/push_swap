/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:30:37 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/26 17:37:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	number;
	int	answer;

	if (nb == 1)
		return (1);
	if (nb < 1)
		return (0);
	number = 1;
	while (number <= 46340)
	{
		answer = number * number;
		if (answer >= nb)
		{
			if (answer == nb)
				return (number);
			break ;
		}
		number++;
	}
	return (0);
}
