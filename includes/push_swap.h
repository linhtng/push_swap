/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:21:10 by thuynguy          #+#    #+#             */
/*   Updated: 2023/02/04 11:33:20 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				place;
	int				sorted_place;
	int				move_a;
	int				move_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*min_index;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
}	t_stacks;

/* ps_atoi */
int		ft_psatoi(const char *str, int *input, int argc, char **argv);

/*ps_valid_input_arr */
void	ft_error_input(void *allocated_mem, int argc, char **argv);
int		*get_arrinput(int argc, char **argv, int *size);

/*ps_stacks_prep */
t_stack	*fill_stack(int *input, int size, int *sorted_arr);
void	ft_error_malloc(void *allocated_mem1, void *allocated_mem2);
t_stack	*ft_ps_lstnew(int data, int *sorted, int size);
void	ft_ps_lstadd_front(t_stack **lst, t_stack *new);
void	ft_ps_lstclear(t_stack **lst);

/* ps_utils */
int		get_max(t_stack *stack);
int		ft_abs(int x);
int		arr_len(char **arv);

/*ps_quicksort */
int		*ft_intdup_sorted(int *src, int size);
void	search_for_data(int *sorted, int size, int data, int *index);

/*ps_swap_instructions */
int		ft_sa(t_stack **a);
int		ft_sb(t_stack **b);

/*ps_rotate_instructions */
int		ft_ra(t_stack **a);
int		ft_rb(t_stack **b);
int		ft_rr(t_stacks *stacks);
void	ft_ps_lstadd_back(t_stack **lst, t_stack *new);

/*ps_rev_rotate_instructions */
int		ft_rra(t_stack **a);
int		ft_rrb(t_stack **a);
int		ft_rrr(t_stacks *stacks);

/* ps_push_instructions */
int		ft_pb(t_stacks *stacks);
int		ft_pa(t_stacks *stacks);

/* ps_sort */
void	ps_push_to_b(t_stacks *stacks, int size);
void	ps_sort3(t_stacks *stacks, int max);
int		get_min_place(t_stack *stack_a);
void	get_min_to_top(t_stacks *stacks, int size, int min_index_place);
void	ps_sort(t_stacks *stacks, int size);

/* ps_sorted_places */
void	get_place(t_stack **stack);
void	needed_moves_to_sorted_place(int size_a, int size_b, t_stacks *stacks);

/* ps_min_moves */
void	get_min_move(t_stack *b, int *min_a, int *min_b);
void	do_min_move(t_stacks *stacks, int min_a, int min_b);
void	rotate_a(t_stack **a, int *move);

#endif
