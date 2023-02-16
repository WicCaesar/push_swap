/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:57:45 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/08 20:10:05 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*ditto;
	t_stack	*last;

	ditto = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = (*stack)->next;
	ditto->next = NULL;
	last->next = ditto;
}

void	ra(t_stack **stacka)
{
	rotate(stacka);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stackb)
{
	rotate(stackb);
	write(1, "rb\n", 3);
}

// Simultaneously rotates both stacks wasting only one move.
void	rr(t_stack **stacka, t_stack **stackb)
{
	rotate(stacka);
	rotate(stackb);
	write(1, "rr\n", 3);
}
