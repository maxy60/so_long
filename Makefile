SRCS		= so_long.c					\
			  

OBJS		= ${SRCS:.c=.o}


NAME		= so_long


CC			= gcc

CCFLAGS	= -g3 -Wall -Werror -Wextra

FLAGS 	= -ldl -Imlx -Lmlx -lmlx -lm -lz -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

INCLUDES	= -I./includes -I./libft

all:		${NAME}


${NAME}:	$(OBJS)
			$(MAKE) bonus -C ./libft
			gcc -L./libft/ $(CCFLAGS) $(OBJS) ./libft/libft.a -o $(NAME) $(FLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@ -Imlx -Ibass

clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
