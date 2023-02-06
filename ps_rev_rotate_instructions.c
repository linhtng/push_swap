/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:50:07 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 20:50:12 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ft_rev_rotate:
*	Iterate though linked list stack a using ptr, get to the second last node,
*	save the pointer to that node in temp, add the last node to the front of
*	the list, second last node now becomes last node (its next pointer is set
*	to NULL).
*/

int	ft_rev_rotate(t_stack **a)
{
	t_stack	*temp;
	t_stack	*ptr;

	if (!*a || !(*a)->next)
		return (0);
	ptr = *a;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	temp = ptr;
	ft_ps_lstadd_front(a, temp->next);
	temp->next = NULL;
	return (1);
}

int	ft_rra(t_stack **a)
{
	if (ft_rev_rotate(a))
	{
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	ft_rrb(t_stack **b)
{
	if (ft_rev_rotate(b))
	{
		ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	ft_rrr(t_stacks *stacks)
{
	if (ft_rev_rotate(&stacks->a) && ft_rev_rotate(&stacks->b))
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
