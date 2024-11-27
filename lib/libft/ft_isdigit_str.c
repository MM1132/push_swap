/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:31:35 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/27 12:36:03 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (ft_isdigit((int)(str[index])) == 0)
		{
			return (0);
		}
		index++;
	}
	return (1);
}
