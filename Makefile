SRCS		= src/so_long.c				\
			  src/parse.c				\
			  src/parse2.c				\
			  src/annexe.c				\
			  src/get_next_line_utils.c	\
			  src/get_next_line.c		\
			  src/move_pers.c			\
			  src/g_error.c				\
			  src/render_image.c

OBJS		= ${SRCS:.c=.o} 

NAME		= so_long


CC			= clang

CCFLAGS	= -g3 -Wall -Werror -Wextra -D BUFFER_SIZE=1

LIB		= -L mlx -l mlx -l mlx_Linux -lX11 -lXext -L libft -l ft

INCLUDES	= -I./libft

%.o: %.c 
		$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

all:		${NAME}

bonus:		${NAME}

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
