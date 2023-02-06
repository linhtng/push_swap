/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:40:44 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 20:40:48 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_pb:
*	Save pointer to the current head node in stack a to pointer temp. Move the 
*	head pointer to the next node. Add the old head node to the front of stack
*	b. Change the size of each stack accordingly. Print pb to the shell.
*/

int	ft_pb(t_stacks *stacks)
{
	t_stack	*temp;

	temp = stacks->a;
	stacks->a = stacks->a->next;
	ft_ps_lstadd_front(&stacks->b, temp);
	stacks->size_a--;
	stacks->size_b++;
	ft_printf("pb\n");
	return (1);
}

/* ft_pb:
*	Similar to ft_pb. Push current head node of stack b to a. Change the size of 
*	each stack accordingly. Print pa to the shell.
*/

int	ft_pa(t_stacks *stacks)
{
	t_stack	*temp;

	temp = stacks->b;
	stacks->b = stacks->b->next;
	ft_ps_lstadd_front(&stacks->a, temp);
	stacks->size_a++;
	stacks->size_b--;
	ft_printf("pa\n");
	return (1);
}
