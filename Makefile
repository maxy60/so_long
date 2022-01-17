SRCS		=
			  

OBJS		= ${SRCS:.c=.o}


NAME		= so_long


CC			= gcc

CCFLAGS 	= -Wall -Werror -Wextra

INCLUDES	= -I./includes -I./libft

all:		${NAME}


${NAME}:	$(OBJS)
			$(MAKE) bonus -C ./libft
			gcc -L./libft/ $(CCFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I
clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
