/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_min_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:28:34 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 20:34:04 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* get_min_move:
*	Start with stack b's head node, min_move is the sum of absolute values of 
*	its move_a and move_b. Iterate through stack b, if any smaller min_move
*	value is found, min_a and min_b takes the value of that node's move_a and 
*	move_b.
*/

void	get_min_move(t_stack *b, int *min_a, int *min_b)
{
	int		min_move;
	int		temp;
	t_stack	*ptr_b;
	t_stack	*temp_ptr;

	ptr_b = b;
	min_move = ft_abs(ptr_b->move_a) + ft_abs(ptr_b->move_b);
	*min_a = ptr_b->move_a;
	*min_b = ptr_b->move_b;
	while (ptr_b)
	{
		temp = ft_abs(ptr_b->move_a) + ft_abs(ptr_b->move_b);
		if (temp < min_move)
		{
			min_move = temp;
			*min_a = ptr_b->move_a;
			*min_b = ptr_b->move_b;
			temp_ptr = ptr_b;
		}
		ptr_b = ptr_b->next;
	}
}

/* rotate_both:
*	While min_a and min_b are both negative, reverse rotate both stack a and b
*	at the same time, increment both numbers by 1 each time. Converstly, while
*	min_a and min_b are both positive, rotate both stack a and b at the same time, 
*	decrement both numbers by 1 each time.
*/

void	rotate_both(t_stacks *stacks, int *min_a, int *min_b)
{
	while (*min_a < 0 && *min_b < 0)
	{
		ft_rrr(stacks);
		(*min_a)++;
		(*min_b)++;
	}
	while (*min_a > 0 && *min_b > 0)
	{
		ft_rr(stacks);
		(*min_a)--;
		(*min_b)--;
	}
}

/* rotate_a:
*	Rotate a to the direction based on the sign of parameter move.
*	If move is positive, rotate upward. Else, rotate downward.
*/
void	rotate_a(t_stack **a, int *move)
{
	while (*move > 0)
	{
		ft_ra(a);
		(*move)--;
	}
	while (*move < 0)
	{
		ft_rra(a);
		(*move)++;
	}
}

void	rotate_b(t_stack **b, int *move)
{
	while (*move > 0)
	{
		ft_rb(b);
		(*move)--;
	}
	while (*move < 0)
	{
		ft_rrb(b);
		(*move)++;
	}
}

/* do_min_move:
*	First rotate both stack a and stack b if possible, then rotate each
*	stack a and b separately. Once rotate is done, push top b to top a.
*/

void	do_min_move(t_stacks *stacks, int min_a, int min_b)
{
	rotate_both(stacks, &min_a, &min_b);
	rotate_a(&stacks->a, &min_a);
	rotate_b(&stacks->b, &min_b);
	ft_pa(stacks);
}
