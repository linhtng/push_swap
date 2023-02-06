/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:43:18 by thuynguy          #+#    #+#             */
/*   Updated: 2023/01/24 14:26:06 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ft_swap:
*	This function is used to swap two numbers.
*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* ft_partition:
*	Choose the pivot as the last number in the array. Numbers in the array < pivot
*	are smaller elems. Index smaller_elems keeps the position of the last smaller
*	elem. Iterate through array *input with index i, if a smaller elem is found,
*	put it to the left of the pivot by using ft_swap. Once all the smaller elems
*	are found, swap the pivot to be right next to the last smaller elem. Now all 
*	the bigger elems are on the right of the pivot in the array. 
*	Return the pivot index.
*/

int	ft_partition(int *input, int begin, int last)
{
	int	pivot;
	int	smaller_elems;
	int	i;

	pivot = input[last];
	i = begin;
	smaller_elems = begin - 1;
	while (i <= last - 1)
	{
		if (input[i] < pivot)
		{
			smaller_elems++;
			ft_swap(&input[smaller_elems], &input[i]);
		}
		i++;
	}
	ft_swap(&input[smaller_elems + 1], &input[last]);
	pivot = smaller_elems + 1;
	return (pivot);
}

/* ft_quicksort:
*	int *data -> array to be sorted, int begin = 1st index, int last = last index.
*	ft_partition return the current pivot index. Separately sort elems befor and 
*	after that pivot. Call this function recursively until begin = last.
*/

void	ft_quicksort(int *data, int begin, int last)
{
	int	pivot;

	if (begin < last)
	{
		pivot = ft_partition(data, begin, last);
		ft_quicksort(data, begin, pivot - 1);
		ft_quicksort(data, pivot + 1, last);
	}
}

/* ft_quicksort:
*	Make a duplicate array of the src array and pass it to ft_quicksort.
*	Return the sorted array.
*/

int	*ft_intdup_sorted(int *src, int size)
{
	int	*dup;
	int	i;

	dup = (int *) malloc(sizeof(int) * size);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	ft_quicksort(dup, 0, size - 1);
	return (dup);
}

/* search_for_data:
*	Seach the place of int data in the array *sorted, value of *index 
*	is place + 1 because place go from 0 to size - 1 and we want index 
*	to be from 1 to size.
*/

void	search_for_data(int *sorted, int size, int data, int *index)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == data)
			*index = i + 1;
		i++;
	}
}
