SRCS	=	push_swap.c\
			instructions.c\
			main.c\
			utils.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(LIB)

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
		
