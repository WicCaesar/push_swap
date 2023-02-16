/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:28:36 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/13 16:32:36 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// For three elements, there are five possible scenarios:
//*1.				  2.		  3.		  4.		  5.
//	 1 sa  3 ra  1		2 sa  1		2 rra 1		3 ra  1		3 sa  2 rra 1
//	 3 --> 1 --> 2		1 --> 2		3 --> 2		1 --> 2		2 --> 3 --> 2
//	 2     2     3		3     3		1     3		2     3		1     1     3
void	sort3(t_stack **stacka)
{
	if ((*stacka)->index < (*stacka)->next->index
		&& (*stacka)->index < (*stacka)->next->next->index)
	{
		sa(stacka);
		ra(stacka);
	}
	else if ((*stacka)->index > (*stacka)->next->index
		&& (*stacka)->index < (*stacka)->next->next->index)
		sa(stacka);
	else if ((*stacka)->index < (*stacka)->next->index
		&& (*stacka)->index > (*stacka)->next->next->index)
		rra(stacka);
	else if ((*stacka)->index > (*stacka)->next->index
		&& (*stacka)->next->index < (*stacka)->next->next->index)
		ra(stacka);
	else if ((*stacka)->index > (*stacka)->next->index
		&& (*stacka)->next->index > (*stacka)->next->next->index)
	{
		sa(stacka);
		rra(stacka);
	}
}

// If stack a is sorted and there's nothing in stack b, it's done! End program.
// While it doesn't happen, checks if the first elements are the smallest.
// If so, pushes to stack b. If not, rotates until it finds the smallest.
// When there is only three elements left in a, sorts them. Once these three are
// sorted, swap the elements in b, so they're sent back in decreasing order.
void	sort5(t_stack **stacka, t_stack **stackb, int size)
{
	int	i;

	i = -1;
	while (i++ < size)
	{
		if (issorted(stacka, size) && ps_stacksize(stackb) == 0)
			return ;
		if ((size == 4 && (*stacka)->index == 0)
			|| (size == 5 && ((*stacka)->index <= 1)))
			pb(stacka, stackb);
		else
			ra(stacka);
	}
	if (!issorted(stacka, 3))
		sort3(stacka);
	if (issorted(stackb, size - 3))
		sb(stackb);
	while (size - 3)
	{
		pa(stacka, stackb);
		size--;
	}
}
