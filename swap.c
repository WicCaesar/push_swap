/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:06:11 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/12 19:21:18 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the first two elements at the top of a stack.
// Does nothing if there is only one or no elements.
void	swap(t_stack **stack)
{
	t_stack	*ditto;

	if ((*stack)->next == NULL)
		return ;
	ditto = *stack;
	*stack = (*stack)->next;
	ditto->next = (*stack)->next;
	(*stack)->next = ditto;
}

void	sa(t_stack **stacka)
{
	if (ps_stacksize(stacka) >= 2)
	{
		swap(stacka);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **stackb)
{
	if (ps_stacksize(stackb) >= 2)
	{
		swap(stackb);
		write(1, "sb\n", 3);
	}
}

// Simultaneously swaps the first elements of both stacks wasting only one move.
void	ss(t_stack **stacka, t_stack **stackb)
{
	if (ps_stacksize(stacka) >= 2 && ps_stacksize(stackb) >= 2)
	{
		swap(stacka);
		swap(stackb);
		write(1, "ss\n", 3);
	}
}
