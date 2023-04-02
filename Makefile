SRCS	=	make_line.c\
			make_index.c\
			instructions.c\
			main.c\
			manager_min.c\
			free_all.c\
			manager_tab.c\
			manager_tab2.c \
			notation.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(LIB) -g -fsanitize=address

RM = rm -f

NAME	=	push_swap

LIBFT	=	libft/libft.a

LIB = ./libft

all:	$(LIBFT) $(NAME)

$(LIBFT):
		@make -C $(LIB) bonus

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L ${LIB} -lft

clean:
		$(RM) $(OBJS)
		@make -C $(LIB) clean

fclean:	clean
		$(RM) $(NAME)
		@make -C $(LIB) fclean

re:		fclean all

