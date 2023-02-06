/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:00:44 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 20:14:30 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ps_push_to_b:
*	Pushs (size - 3) numbers from stack a to b. If the size of the stack > 5,
*	first push the smaller half then the bigger half, to help with sorting 
*	efficiency later. For size <= 5, go directly to the second while loop and
*	push if the index is 1 or 2.
*/

void	ps_push_to_b(t_stacks *stacks, int size)
{
	int	pushes;

	pushes = 0;
	while (pushes < (size - 3) / 2 && size > 5)
	{
		if (stacks->a->index < size / 2)
			pushes += ft_pb(stacks);
		else
			ft_ra(&stacks->a);
	}
	while (stacks->size_a > 3)
	{
		if (stacks->a->index < size - 2)
			ft_pb(stacks);
		else
			ft_ra(&stacks->a);
	}
}

/* ps_sort3:
*	Function to sort 3 numbers. If the max number is on top or at the middle, 
*	put it to the bottom. If the 1st number > 2nd number, swap their places.
*/

void	ps_sort3(t_stacks *stacks, int max)
{
	if (stacks->a->data == max)
		ft_ra(&stacks->a);
	if (stacks->a->next->data == max)
		ft_rra(&stacks->a);
	if (stacks->a->data > stacks->a->next->data)
		ft_sa(&stacks->a);
}

/* get_min_place:
*	Get the place of all nodes in list a.
*	Find the place of the node that has index = 1.
*/

int	get_min_place(t_stack *stack_a)
{
	t_stack	*ptr;

	ptr = stack_a;
	get_place(&stack_a);
	while (ptr)
	{
		if (ptr->index == 1)
			return (ptr->place);
		ptr = ptr->next;
	}
	return (0);
}

/* get_min_to_top:
*	If min is in the bottom half of the list, move is negative.
*	Else if min is in the top half, move is positive.
*	Pass stack a and move to rotate_a to do the rotate.
*/

void	get_min_to_top(t_stacks *stacks, int size, int min_index_place)
{
	int	move;

	if (min_index_place > size / 2)
		move = (size - min_index_place) * -1;
	else
		move = min_index_place;
	rotate_a(&stacks->a, &move);
}

/* ps_sort:
*	1) Push all number from stack a to b but the 3 biggest number.
*	2) Sort those 3 using ps_sort3. 
*	3) For each number in stack b, find the needed
*	move to its sorted place in stack a.
*	4) Get the minimum moves of all the numbers in b.
*	5) Do that minimum move and push top b to top a.
*	6) Repeat step 3 to 5 until stack b is empty.
*	7) Now all the numbers are in stack a, find the place of the min index.
*	8) Get the min index to the top of stack a. Voila!
*/

void	ps_sort(t_stacks *stacks, int size)
{
	int	min_move_a;
	int	min_move_b;
	int	min_index_place;

	min_move_a = 0;
	min_move_b = 0;
	ps_push_to_b(stacks, size);
	ps_sort3(stacks, stacks->max);
	while (stacks->size_b)
	{
		needed_moves_to_sorted_place(stacks->size_a, stacks->size_b, stacks);
		get_min_move(stacks->b, &min_move_a, &min_move_b);
		do_min_move(stacks, min_move_a, min_move_b);
	}
	if (stacks->a->index != 1)
	{
		min_index_place = get_min_place(stacks->a);
		get_min_to_top(stacks, size, min_index_place);
	}
}
