SRCS	=	make_line.c\
			make_index.c\
			instructions.c\
			main.c\
			manager_min.c\
			free_all.c\
			manager_tab.c\
			manager_tab2.c \
			conditions.c\
			push_in_b.c\
			push_in_a.c\
			patern_line.c\
			patern_line2.c\
			patern_line3.c\
			push_in_sort_a.c\
			push_pattern.c


OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(LIB) -I $(LIBPRF) -g -fsanitize=address

RM = rm -f

NAME	=	push_swap

LIBFT	=	libft/libft.a

LIB = ./libft

LIBFTPRINTF = printf/libftprintf.a

LIBPRF = ./printf

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

