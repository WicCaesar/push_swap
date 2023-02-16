/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:11:37 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/14 10:59:03 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sumbits(t_stack **stack, int size);
void	sorta(t_stack **stacka, t_stack **stackb, int bit);

void	radix(t_stack **stacka, t_stack **stackb, int size)
{
	int	bit;
	int	max;
	int	i;

	max = (sumbits(stacka, size));
	bit = -1;
	while (++bit < max)
	{
		i = 0;
		size = ps_stacksize(stacka);
		while (i++ < size && size != 0)
			sorta(stacka, stackb, bit);
		i = ps_stacksize(stackb);
		while (i-- > 0)
			pa(stacka, stackb);
	}
	if (issorted(stacka, size) && stackb == NULL)
		return ;
}

// Finds the highest value in a stack and returns the number of bits needed to
// represent it by dividing it by 2 until it is less than 1.
// For instance, 5 needs 3 bits to be represented (101), 100 needs 7 (1100100).
int	sumbits(t_stack **stack, int size)
{
	static int	i;
	static int	highestvalue;
	static int	amountofbits;
	t_stack		*ditto;

	ditto = *stack;
	while (i < size && ditto->next != NULL)
	{
		if (ditto->index > highestvalue)
			highestvalue = ditto->index;
		ditto = ditto->next;
		i++;
	}
	while (highestvalue > 1)
	{
		highestvalue /= 2;
		amountofbits++;
	}
	amountofbits++;
	return (amountofbits);
}

// If a given bit is 0, push it to stackb, otherwise rotate it to the bottom
// so other value can be assessed.
void	sorta(t_stack **stacka, t_stack **stackb, int bit)
{
	if (((*stacka)->index & (1 << bit)) == 0)
		pb(stacka, stackb);
	else
		ra(stacka);
}
