/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:53:09 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/11 22:16:45 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	if (lst == NULL)
		return (0);
	size = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int	ps_stacksize(t_stack **stack)
{
	size_t	size;
	t_stack	*temp;

	if (stack == NULL || !*stack)
		return (0);
	size = 1;
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
