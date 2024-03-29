# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleung <oleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:55:22 by oleung            #+#    #+#              #
#    Updated: 2023/12/10 15:07:28 by oleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFTNAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = 	ft_printf.c \
		ft_printptr.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printnbr.c \
		ft_printnbr_unsigned.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

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

norm: $(SRCS)
	norminette ft_*.c $(LIBFTDIR)/*.c ft_*.h $(LIBFTDIR)/*.h

format: $(SRCS)
	python3 -m c_formatter_42 ft_*.c ft_*.h
	make norm

.PHONY: bonus all clean fclean re norm format