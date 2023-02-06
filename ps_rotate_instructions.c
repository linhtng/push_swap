/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:46:38 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 20:46:41 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_ps_lstadd_back(t_stack **lst, t_stack *new)
{
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
}

/* ft_rotate:
*	Save the pointer to the current head node of the list to temp. Move the 
*	head pointer to the next node. Add the old head node to the back of the
*	list. It now becomes the tail node of the list.
*/

int	ft_rotate(t_stack **a)
{
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_ps_lstadd_back(a, temp);
	return (1);
}

int	ft_ra(t_stack **a)
{
	if (ft_rotate(a))
	{
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	ft_rb(t_stack **b)
{
	if (ft_rotate(b))
	{
		ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	ft_rr(t_stacks *stacks)
{
	if (ft_rotate(&stacks->a) && ft_rotate(&stacks->b))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}
