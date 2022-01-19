SRCS		= so_long.c					\

OBJS		= ${SRCS:.c=.o} 

NAME		= so_long


CC			= gcc

CCFLAGS	= -g3 -Wall -Werror -Wextra

LIB		= -L mlx -l mlx -l mlx_Linux -lX11 -lXext -L libft -l ft

INCLUDES	= -I./libft

%.o: %.c 
		$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

all:		${NAME}


${NAME}:	$(OBJS)
			make bonus -C ./libft
			$(CC) $(CCFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
