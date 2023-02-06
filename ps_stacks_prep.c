/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_prep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:45:58 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/02 19:51:22 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_malloc(void *allocated_mem1, void *allocated_mem2)
{
	if (allocated_mem1)
		free(allocated_mem1);
	if (allocated_mem2)
		free(allocated_mem2);
	ft_printf("Error\n");
	exit(1);
}

/* ft_ps_lstnew:
*	Allocates with malloc and returns a new node.
*	The member variable 'data' is initialized with
*	the value of the parameter 'data'.  The variable
* 	'index' is initialized by passing it to search_for_data function.
*	The rest of the variables are set to 0 and 'next' is initialized to NULL.
*/

t_stack	*ft_ps_lstnew(int data, int *sorted, int size)
{
	t_stack	*newlink;

	newlink = (t_stack *) malloc(sizeof(t_stack));
	if (newlink)
	{
		newlink->data = data;
		search_for_data(sorted, size, data, &newlink->index);
		newlink->place = 0;
		newlink->sorted_place = 0;
		newlink->move_a = 0;
		newlink->move_b = 0;
		newlink->next = NULL;
	}
	else
		return (NULL);
	return (newlink);
}

void	ft_ps_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_ps_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = (ptr)->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}

/* fill_stack:
*	Fill the stack with input from params int *input and *sorted_arr
*	For size times, create a new node, if malloc error, clear the
*	list so far. If no error, add that new node to the front of the list.
*	Return pointer to the head node of the filled stack a.
*/

t_stack	*fill_stack(int *input, int size, int *sorted_arr)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	int		length;

	stack_a = NULL;
	length = size;
	size--;
	while (size >= 0)
	{
		new_node = ft_ps_lstnew(input[size], sorted_arr, length);
		if (!new_node)
		{
			ft_ps_lstclear(&stack_a);
			return (NULL);
		}
		ft_ps_lstadd_front(&stack_a, new_node);
		size--;
	}
	return (stack_a);
}
