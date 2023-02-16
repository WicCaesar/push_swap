/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:44:15 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/14 08:26:23 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leadingzeroes(char **values);
int		duplicates(t_stack *stacka);
int		setindex(const char *s1, const char *s2);
int		outofrange(char **values);
void	ft_error(t_stack **stack);

// Parsing a string of characters is analysing the syntax of this string to find
// tokens, or items, and then create a structure from the result.

// Leading zeroes are redundant, so they are removed. If the string is empty
// after removing the zeroes, it is replaced by "0".
void	leadingzeroes(char **values)
{
	int	i;
	int	j;

	i = 0;
	while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			if (values[i][j] == '+' || values[i][j] == '-')
				j++;
			else if (values[i][j] == '0')
				j++;
			else if (values[i][j] == '\0')
				values[i] = "0";
			else
				j++;
		}
		i++;
	}
}

// Duplicates are not allowed. The function returns 1 if there are duplicates.
int	duplicates(t_stack *stacka)
{
	t_stack	*element;
	t_stack	*comparison;

	element = stacka;
	while (element)
	{
		comparison = element->next;
		while (comparison)
		{
			if (element->value == comparison->value)
				return (1);
			comparison = comparison->next;
		}
		element = element->next;
	}
	return (0);
}

// Sets the index to the first relevant digit (not a plus sign or leading zero).
int	setindex(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	if (s1[index] == '+')
	{
		if (s2[0] != '+')
			index++;
	}
	while (s1[index] == '0')
		index++;
	return (index);
}

// If the value is larger than a type int, returns 1.
int	outofrange(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		if (ft_atolli(values[i]) > INT_MAX || ft_atolli(values[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

// Just for saving lines.
void	ft_error(t_stack **stack)
{
	if (stack == NULL || *stack != NULL)
		ps_stackclear(stack, free);
	write(2, "Error\n", 6);
	exit (0);
}
