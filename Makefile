# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:55:22 by oleung            #+#    #+#              #
#    Updated: 2023/12/08 12:11:04 by oleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFTNAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar r
RM = rm -rf

SRCS = 	ft_printf.c \
		ft_putnbr_base_fd.c \
		ft_putptr_fd.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

$(LIBFTNAME):
	make -C $(LIBFTDIR) all

$(NAME): $(LIBFTNAME) $(OBJS)
	cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	$(AR) $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re