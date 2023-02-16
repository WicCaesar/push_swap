/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:02:23 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/08 20:10:19 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last;

	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stacka)
{
	reverse(stacka);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stackb)
{
	reverse(stackb);
	write(1, "rrb\n", 4);
}

// Simultaneously reverses both stacks wasting only one move.
void	rrr(t_stack **stacka, t_stack **stackb)
{
	reverse(stacka);
	reverse(stackb);
	write(1, "rrr\n", 4);
}
