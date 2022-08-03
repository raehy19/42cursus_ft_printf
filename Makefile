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

NAME := ft_printf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar
ARFLAG := crs

SRCS := \
	ft_printf.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re

