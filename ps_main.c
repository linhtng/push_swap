/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:14:50 by thuynguy          #+#    #+#             */
/*   Updated: 2023/01/26 19:07:18 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack_sorted:
*	Iterate through linked list from the start. If a node's data is bigger
*	than its next node's data, list is not sorted, return 0. Otherwise,
*	return 1.
*/

int	stack_sorted(t_stack *a, int size)
{
	t_stack	*iter;
	t_stack	*ptr;

	if (size == 1)
		return (1);
	ptr = a;
	while (ptr->next != NULL)
	{
		iter = ptr->next;
		if (ptr->data > iter->data)
			return (0);
		ptr = iter;
	}
	return (1);
}

/* begin_sort:
*	Different action for when stack a's size is 2, 3 or else.
*/

void	begin_sort(t_stacks *stacks, int size)
{
	if (size == 2)
	{
		if (stacks->a->index != 1)
			ft_sa(&stacks->a);
		return ;
	}
	if (size == 3)
		ps_sort3(stacks, stacks->max);
	else
		ps_sort(stacks, size);
}

/* free_stacks:
*	Iterate through linked list stack a to free all the nodes in it.
*	Free stacks.
*/

void	free_stacks(t_stacks *stacks)
{
	while (stacks->a)
	{
		free(stacks->a);
		stacks->a = stacks->a->next;
	}
	free(stacks);
}

/* ft_push_swap:
*	Get the sorted array. Initialize stacks. Fill stack a with input
*	from int *input and sorted array. Stack b and min_index are empty.
*	Pass stacks to begin_sort to get sorted. Free everthing.
*/

void	ft_push_swap(int *input, int size)
{
	t_stacks	*stacks;
	int			*sorted_arr;

	sorted_arr = ft_intdup_sorted(input, size);
	if (!sorted_arr)
		ft_error_malloc(input, NULL);
	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error_malloc(input, sorted_arr);
	stacks->a = fill_stack(input, size, sorted_arr);
	if (!stacks->a)
		ft_error_malloc(input, sorted_arr);
	stacks->b = NULL;
	stacks->min_index = NULL;
	stacks->size_a = size;
	stacks->size_b = 0;
	stacks->min = sorted_arr[0];
	stacks->max = sorted_arr[size - 1];
	free(input);
	free(sorted_arr);
	if (!stack_sorted(stacks->a, size))
		begin_sort(stacks, size);
	free_stacks(stacks);
}

/* main:
*	First create an array of integer to store the valid inputs
*	then pass it to ft_push_swap to create stack and begin sorting. 
*/

int	main(int argc, char **argv)
{
	int	*data_input;
	int	size;

	size = 0;
	if (argc > 1)
	{
		data_input = get_arrinput(argc, argv, &size);
		if (data_input && size != 1)
			ft_push_swap(data_input, size);
	}
	return (0);
}
