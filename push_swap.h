/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:51:12 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/14 08:03:30 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

char	**formatting(int argc, char **argv);
int		fillstack(char **values, int index, t_stack *stacka);
void	ft_error(t_stack **stacka);
int		parsing(char **values);
void	leadingzeroes(char **values);
int		setindex(const char *s1, const char *s2);
int		outofrange(char **values);
int		duplicates(t_stack *stacka);
int		issorted(t_stack **stack, int size);
int		indexer(char **argv, int value);
void	sort3(t_stack **stacka);
void	sort5(t_stack **stacka, t_stack **stackb, int size);
void	swap(t_stack **stack);
void	sa(t_stack **stacka);
void	sb(t_stack **stackb);
void	ss(t_stack **stacka, t_stack **stackb);
void	pushto(t_stack **destination, t_stack **origin);
void	pa(t_stack **stacka, t_stack **stackb);
void	pb(t_stack **stacka, t_stack **stackb);
void	rotate(t_stack **stack);
void	ra(t_stack **stacka);
void	rb(t_stack **stackb);
void	rr(t_stack **stacka, t_stack **stackb);
void	reverse(t_stack **stack);
void	rra(t_stack **stacka);
void	rrb(t_stack **stackb);
void	rrr(t_stack **stacka, t_stack **stackb);
void	radix(t_stack **stacka, t_stack **stackb, int size);
int		sumbits(t_stack **stack, int size);
void	sorta(t_stack **stacka, t_stack **stackb, int bit);
void	sortb(t_stack **stacka, t_stack **stackb, int bit, int max);
t_stack	*ps_stacknew(int content);
int		ps_stacksize(t_stack **stack);
t_stack	*ps_stacklast(t_stack *stack);
void	ps_stackadd_front(t_stack **stack, t_stack *newnode);
void	ps_stackadd_back(t_stack **stack, int value, int index);
void	ps_stackdelone(t_stack *stack, void (*del)(void *));
void	ps_stackclear(t_stack **stack, void (*del)(void *));
void	ps_matrixclear(char **matrix);
#endif
