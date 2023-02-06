/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted_places.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:20:00 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 20:25:19 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_place:
*	Assigns a place to each node of the stack from top to bottom
*	in ascending order, places will be from 0 to (stack size - 1).
*/

void	get_place(t_stack **stack)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack;
	while (ptr)
	{
		ptr->place = i;
		i++;
		ptr = ptr->next;
	}
}

/* find_closest_smaller_index:
*	Find a node in stack a that has smaller index than b->index AND
*	closest to it. Example:
*	B index: 5
*	A contains indexes: 3 7 8 4
*	Both 3 and 4 are smaller than 5 but 4 is closer to 5 than 3, so
*	b->sorted_place is behind 4.
*/

int	find_closest_smaller_index(t_stack *a, t_stack *b)
{
	t_stack	*ptr;
	t_stack	*res;
	int		temp;

	ptr = a;
	temp = 0;
	res = NULL;
	while (ptr)
	{
		if (ptr->index > temp && ptr->index < b->index)
		{
			temp = ptr->index;
			res = ptr;
		}
		ptr = ptr->next;
	}
	if (res)
	{
		b->sorted_place = res->place + 1;
		return (1);
	}
	return (0);
}

void	find_closest_bigger_index(t_stack *a, t_stack *b)
{
	t_stack	*ptr;
	t_stack	*res;
	int		temp;
	int		diff;

	ptr = a;
	if (ptr->index > b->index)
	{
		temp = ptr->index - b->index;
		res = ptr;
	}
	while (ptr)
	{
		diff = ptr->index - b->index;
		if (ptr->index > b->index && diff < temp)
		{
			temp = diff;
			res = ptr;
		}
		ptr = ptr->next;
	}
	if (res->place - 1 > 0)
		b->sorted_place = res->place;
}

/* find_sorted_place:
*	Sorted place is a place in stack a where node *b has to be
*	in order to be correctly sorted.
*	1st priority: sandwich position where it could be in between
*	a smaller index and a bigger index.
*	2nd priority: behind its closest smaller index.
*	3rd priority: in front of the closest bigger index (i.e the current
*	smallest index in stack a).
*/

void	find_sorted_place(t_stack *a, t_stack *b)
{
	t_stack	*ptr;

	ptr = a;
	b->sorted_place = 0;
	while (ptr->next)
	{
		if (b->index > ptr->index)
		{
			if (b->index < ptr->next->index)
			{
				b->sorted_place = ptr->place + 1;
				return ;
			}
		}
		ptr = ptr->next;
	}
	b->sorted_place = 0;
	if (!find_closest_smaller_index(a, b))
		find_closest_bigger_index(a, b);
}

/* needed_moves_to_sorted_place:
*	1) Get place of all nodes in stack a and b.
*	2) Iterate through b with pointer ptr_b.
*	3) For each node in stack b, find its sorted place in stack a.
*	4) Its move_a is number of move to get it from top a to its
*	sorted place in a. The sign of the move depends on which half 
*	the sorted place is in, bottom half or top half.
*	5) Its move_b is number of move to get it to top b from its
*	current place in b. The sign of the move depends on which half 
*	its current place is in, bottom half or top half.
*	6) Do steps 3 to 5 for all nodes in stack b.
*/

void	needed_moves_to_sorted_place(int size_a, int size_b, t_stacks *stacks)
{
	t_stack	*ptr_b;

	get_place(&stacks->a);
	get_place(&stacks->b);
	ptr_b = stacks->b;
	while (ptr_b)
	{
		find_sorted_place(stacks->a, ptr_b);
		if (ptr_b->sorted_place > size_a / 2)
			ptr_b->move_a = (size_a - ptr_b->sorted_place) * (-1);
		else
			ptr_b->move_a = ptr_b->sorted_place;
		if (ptr_b->place > size_b / 2)
			ptr_b->move_b = (size_b - ptr_b->place) * (-1);
		else
			ptr_b->move_b = ptr_b->place;
		ptr_b = ptr_b->next;
	}
}
