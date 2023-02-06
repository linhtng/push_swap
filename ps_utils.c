/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:20 by thuynguy          #+#    #+#             */
/*   Updated: 2023/01/17 13:51:36 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_max:
*	Get the maximum data of all nodes in stack.
*/

int	get_max(t_stack *stack)
{
	t_stack	*ptr;
	int		max;

	ptr = stack;
	max = stack->data;
	while (ptr->next != NULL)
	{
		ptr = (ptr)->next;
		if (ptr->data > max)
			max = ptr->data;
	}
	return (max);
}

/* ft_abs:
*	Return absolute value of a number.
*/

int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

/* arr_len:
*	Return the number of strings in a null-terminated array of strings.
*/

int	arr_len(char **arv)
{
	int	len;

	len = 0;
	while (*arv)
	{
		len++;
		arv++;
	}
	return (len);
}
