# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 14:55:50 by rjeong            #+#    #+#              #
#    Updated: 2022/08/03 14:55:52 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar
ARFLAG := crs
LIBFT_DIR := libft

SRCS = \
	ft_printf.c \
	ft_printf_functions_1.c \
	ft_printf_functions_2.c \

SRCS_BONUS = \
	ft_printf_bonus.c \
	ft_printf_functions_1_bonus.c \
	ft_printf_functions_2_bonus.c \
	ft_printf_parse_functions_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR) all
	cp $(LIBFT_DIR)/libft.a ./$(NAME)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean
	make all

bonus : $(OBJS_BONUS)
	make OBJS="$(OBJS_BONUS)" all

#run : bonus
#	gcc libftprintf.a main.c
#	./a.out

.PHONY : all clean fclean re bonus

