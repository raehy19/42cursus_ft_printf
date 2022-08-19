# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 14:55:50 by rjeong            #+#    #+#              #
#    Updated: 2022/08/18 11:35:01 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
BONUS_NAME := libftprintf_bonus.a
LIBFT := ./libft/libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar
ARFLAG := crs
LIBFT_DIR := libft

PRINTF_SRCS := \
	ft_printf.c \
	ft_printf_functions_1.c \
	ft_printf_functions_2.c

PRINTF_SRCS_BONUS := \
	ft_printf_bonus.c \
	ft_printf_parse_functions_bonus.c \
	ft_printf_functions_1_bonus.c \
	ft_printf_functions_2_bonus.c \
	ft_printf_functions_utils_1_bonus.c \
	ft_printf_functions_utils_2_bonus.c

PRINTF_OBJS := $(PRINTF_SRCS:.c=.o)

PRINTF_OBJS_BONUS := $(PRINTF_SRCS_BONUS:.c=.o)

all : bonus

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(PRINTF_OBJS)
	$(RM) $(PRINTF_OBJS_BONUS)

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(BONUS_NAME)
	$(RM) $(NAME)

re : fclean
	make all

bonus : $(BONUS_NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(NAME) : $(LIBFT) $(PRINTF_OBJS)
	cp $(LIBFT) ./$(NAME)
	$(AR) $(ARFLAG) $@ $^

$(BONUS_NAME) : $(LIBFT) $(PRINTF_OBJS_BONUS)
	cp $(LIBFT) ./$(BONUS_NAME)
	$(AR) $(ARFLAG) $@ $^
	cp $(BONUS_NAME) ./$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all bonus clean fclean re

