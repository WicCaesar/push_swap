/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:17:35 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/14 08:04:54 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the index of each value that will go in the stack, 
// based on the number of values smaller than it.
int	indexer(char **argv, int value)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (argv[i])
	{
		if (value > ft_atolli(argv[i]))
			index++;
		i++;
	}
	return (index);
}

int	issorted(t_stack **stack, int size)
{
	int		i;
	t_stack	*ditto;

	i = 0;
	ditto = *stack;
	while (ditto->next != NULL)
	{
		if (ditto->value < ditto->next->value)
			i++;
		ditto = ditto->next;
	}
	if ((size - 1) - i == 0)
		return (1);
	return (0);
}
