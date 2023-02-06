/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_valid_input_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:13:01 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/04 15:31:59 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

void	ft_error_input(void *allocated_mem, int argc, char **argv)
{
	if (allocated_mem)
		free(allocated_mem);
	if (argc == 2)
		free_arr(argv);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

/* fill_arrinput:
*	Fill all index in array *input with results from ft_psatoi,
*	if there are duplicated number, clean exit using ft_error_input
*/

void	fill_arrinput(int *input, char **arv, int len, int arc)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		input[i] = ft_psatoi(arv[i], input, arc, arv);
		while (j < i)
		{
			if (input[j] == input[i])
				ft_error_input(input, arc, arv);
			j++;
		}
		i++;
	}
}

int	*make_arrint(int len, char **argv, int argc)
{
	int	*res;

	res = (int *) malloc(sizeof(int) * len);
	if (res)
		fill_arrinput(res, argv, len, argc);
	if (argc == 2)
		free_arr(argv);
	return (res);
}

/* get_arrinput:
*	If only one argument given, i.e numbers are passed as a single string,
*	use ft_split to get an array of strings obtained by splitting argv[1]
*	using the character ’ ’ as a delimiter. If there is only 1 string in 
*	the array, check if it is a number (to print out Error if needed), then
*	clean exit. Else if there are multiple strings, return an array of integers
*	that stores all the valid input.
*/

int	*get_arrinput(int argc, char **argv, int *size)
{
	int	arg_len;

	argv++;
	if (argc == 2)
	{
		argv = ft_split(*argv, ' ');
		arg_len = arr_len(argv);
		if (arg_len == 1)
		{
			ft_psatoi(argv[0], NULL, argc, argv);
			free_arr(argv);
			return (NULL);
		}
		*size = arg_len;
		return (make_arrint(arg_len, argv, argc));
	}
	arg_len = argc - 1;
	*size = arg_len;
	return (make_arrint(arg_len, argv, argc));
}
