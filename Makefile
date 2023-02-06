# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thuynguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 15:30:29 by thuynguy          #+#    #+#              #
#    Updated: 2022/11/22 15:30:31 by thuynguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g3

SRC = ps_atoi.c \
	ps_valid_input_arr.c \
	ps_main.c \
	ps_utils.c \
	ps_stacks_prep.c \
	ps_quicksort.c \
	ps_sort.c \
	ps_sorted_places.c \
	ps_min_moves.c \
	ps_push_instructions.c \
	ps_swap_instructions.c \
	ps_rotate_instructions.c \
	ps_rev_rotate_instructions.c \

OBJSFD 	= objs

OBJS 	= $(addprefix $(OBJSFD)/,$(SRC:.c=.o))

HDR 		= -I./includes

FT_PRINTF_HDR 	= -I./includes/ft_printf

FT_PRINTF_BINARY	= -L./includes/ft_printf -lftprintf

FT_PRINTF		= ./includes/ft_printf/libftprintf.a

all: $(FT_PRINTF) ./includes/ft_printf/libftprintf.a $(NAME)

FT_PRINTF		= ./includes/ft_printf/libftprintf.a

$(FT_PRINTF):
			make -C ./includes/ft_printf

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) $(HDR) $(FT_PRINTF_HDR) -c $< -o $@

$(NAME): $(OBJS) $(FT_PRINTF) ./includes/push_swap.h
	gcc -g $(OBJS) $(FT_PRINTF_BINARY) -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./includes/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./includes/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
