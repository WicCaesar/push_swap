/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:10:58 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/13 16:29:19 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Takes the element at the top of a stack and puts it at the top of another.
// Does nothing if the stack is empty.
void	pushto(t_stack **destination, t_stack **origin)
{
	t_stack	*ditto;

	if (!*origin)
		return ;
	ditto = *origin;
	*origin = (*origin)->next;
	ditto->next = *destination;
	*destination = ditto;
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	if (ps_stacksize(stackb) >= 1)
	{
		pushto(stacka, stackb);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	if (ps_stacksize(stacka) >= 1)
	{
		pushto(stackb, stacka);
		write(1, "pb\n", 3);
	}
}
