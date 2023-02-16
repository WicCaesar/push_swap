/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:50:55 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/14 10:14:46 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**formatting(int argc, char **argv);
int		fillstack(char **values, int index, t_stack *stacka);
int		parsing(char **values);
int		push_swap(t_stack **stacka, int size);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		argv = formatting(argc, argv);
		fillstack(argv, 0, NULL);
	}
	return (0);
}

// Standardises the input into a single array of strings for easier handling.
char	**formatting(int argc, char **argv)
{
	int		i;
	char	*ditto;
	char	*arrayofvalues;

	i = 2;
	arrayofvalues = ft_strjoin(argv[1], " ");
	while (i < argc)
	{
		ditto = arrayofvalues;
		arrayofvalues = ft_strjoin(arrayofvalues, " ");
		free(ditto);
		ditto = arrayofvalues;
		arrayofvalues = ft_strjoin(arrayofvalues, argv[i]);
		free(ditto);
		i++;
	}
	argv = ft_split(arrayofvalues, ' ');
	if (argv[0] == NULL)
		ft_error(NULL);
	i = 0;
	while (argv[i])
		if (ft_strlen(argv[i++]) > 11)
			ft_error(NULL);
	free(arrayofvalues);
	return (argv);
}

// Stacks are efficient data structures for storing and retrieving data in a
// LIFO order. Allows data retrieval in the opposite order as it was stored.
// Queues are efficient data structures useful for storing and retrieving data
// in a FIFO order. Allows data retrieval in the same order as it was stored.
// Lists are abstract data types that represents an ordered collection of
// elements, with duplicates allowed. It has a wide range of operations, like
// inserting an element at a specified position, deleting, searching, etc.
int	fillstack(char **values, int index, t_stack *stacka)
{
	if (parsing(values))
		ft_error(&stacka);
	while (values[index] != NULL)
	{
		ps_stackadd_back(&stacka, ft_atolli(values[index]),
			indexer(values, ft_atolli(values[index])));
		index++;
	}
	if (duplicates(stacka))
		ft_error(&stacka);
	if (issorted(&stacka, ps_stacksize(&stacka)))
	{
		ps_stackclear(&stacka, free);
		ps_matrixclear(values);
		exit (0);
	}
	else
	{
		push_swap(&stacka, ps_stacksize(&stacka));
		ps_stackclear(&stacka, free);
		ps_matrixclear(values);
	}
	return (0);
}

int	parsing(char **values)
{
	int	index;

	index = 0;
	while (values[index])
	{
		if (!ft_isint(values[index]))
			return (1);
		index++;
	}
	leadingzeroes(values);
	if (outofrange(values))
		return (1);
	return (0);
}

// Sets which path to follow according to the number of values given.
int	push_swap(t_stack **stacka, int size)
{
	t_stack	*stackb;

	stackb = NULL;
	if (size == 2)
		sa(stacka);
	else if (size == 3)
		sort3(stacka);
	else if (size >= 4)
	{
		if (size <= 5)
			sort5(stacka, &stackb, size);
		if (size > 5)
			radix(stacka, &stackb, size);
		ps_stackclear(&stackb, free);
	}
	return (0);
}
