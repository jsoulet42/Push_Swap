SRCS	=	main.c\
			main_suit.c\
			conditions.c\
			get_next_line.c\
			get_next_line_utils.c\
			instructions_1.c


OBJS		=	$(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I $(LIB) -I $(LIBPRF) -g
RM			=	rm -f
NAME		=	checker
LIBFT		=	libft/libft.a
LIB			=	./libft
LIBFTPRINTF	= printf/libftprintf.a
LIBPRF		= ./printf

all:	$(LIBFT) $(LIBFTPRINTF) $(NAME)

$(LIBFT):
		@make -C $(LIB) bonus

$(LIBFTPRINTF):
		@make -C $(LIBPRF)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L ${LIB} -lft -L ${LIBPRF} -lftprintf

clean:
		$(RM) $(OBJS)
		@make -C $(LIB) clean
		@make -C $(LIBPRF) clean

fclean:	clean
		$(RM) $(NAME)
		@make -C $(LIB) fclean
		@make -C $(LIBPRF) fclean

re:		fclean all

