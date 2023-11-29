# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:55:22 by oleung            #+#    #+#              #
#    Updated: 2023/11/29 09:04:11 by oleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -r
RM = rm -f

SRCS = ft_printf.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	$(AR) $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(LIBFTDIR) && make fclean

re: clean all

.PHONY: bonus all clean fclean re