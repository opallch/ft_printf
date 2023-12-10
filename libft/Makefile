# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleung <oleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:55:22 by oleung            #+#    #+#              #
#    Updated: 2023/12/10 15:06:33 by oleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS = ft_strnstr.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strtrim.c \
	ft_striteri.c \
	ft_isdigit.c \
	ft_memcmp.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_bzero.c \
	ft_isascii.c \
	ft_strchr.c \
	ft_strmapi.c \
	ft_strjoin.c \
	ft_strdup.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_tolower.c \
	ft_strrchr.c \
	ft_putnbr_fd.c \
	ft_strncmp.c \
	ft_putchar_fd.c \
	ft_itoa.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_split.c \
	ft_toupper.c \
	ft_substr.c \
	ft_atoi.c \
	ft_memset.c 

SRCS_B  = 	ft_lstnew.c \
	  		ft_lstadd_front.c \
	  		ft_lstsize.c \
	  		ft_lstlast.c \
	  		ft_lstadd_back.c \
	  		ft_lstdelone.c \
	  		ft_lstclear.c \
	  		ft_lstiter.c \
	  		ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: bonus all clean fclean re