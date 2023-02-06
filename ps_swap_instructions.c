/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:43:46 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 20:43:49 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_do_swap:
*	Save pointer to the current '3rd from the top' node in stack a to pointer 
*	temp. Move the head pointer to the current '2nd from the top' node. 
*	Its next variable now points at the old head node. So old head node now
*	becomes second node. Set its next pointer to temp. There we have the original 
*	top and 2nd node swapped their position.
*/

int	ft_do_swap(t_stack **a)
{
	t_stack	*temp;
	t_stack	**iter;

	if (!*a || !(*a)->next)
		return (0);
	iter = &(*a)->next->next;
	temp = *iter;
	ft_ps_lstadd_front(a, (*a)->next);
	(*a)->next->next = temp;
	return (1);
}

int	ft_sa(t_stack **a)
{
	if (ft_do_swap(a))
	{
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	ft_sb(t_stack **b)
{
	if (ft_do_swap(b))
	{
		ft_printf("sb\n");
		return (1);
	}
	return (0);
}
