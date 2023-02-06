/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psatoi.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:49:58 by thuynguy          #+#    #+#             */
/*   Updated: 2023/01/21 16:59:36 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow(long result)
{
	return (result > INT_MAX || result < INT_MIN);
}

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n' || c == ' ');
}

/* atoi_sign:
*	Get the sign of the number and return the pointer to the character after
*	the sign (if any) in the string str.
*/

const char	*atoi_sign(const char *str, int *sign)
{
	if (*str == '-')
	{
		*sign = -1;
		str++;
		return (str);
	}
	if (*str == '+')
		str++;
	return (str);
}

/* ft_psatoi:
*	Convert string to integer for push_swap. If string ends right after space
*	and/or sign, or any non-digit char in str, or the results overflow,
*	print error and free allocated mem.
*/

int	ft_psatoi(const char *str, int *input, int argc, char **argv)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	str = atoi_sign(str, &sign);
	if (!*str)
		ft_error_input(input, argc, argv);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error_input(input, argc, argv);
		else
			result = result * 10 + *str - '0';
		str++;
	}
	result = result * sign;
	if (overflow(result))
		ft_error_input(input, argc, argv);
	return (result);
}
