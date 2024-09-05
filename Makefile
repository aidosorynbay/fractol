SRC			=	main.c init.c utils.c events.c render.c atodbl.c

OBJS		=	${SRC:.c=.o}

CC			=	cc

NAME		=	fractol

CFLAGS		=	-Wall -Wextra -Werror

MLXDIR		=	./minilibx

MLX			=	${MLXDIR}/libmlx.a

LIBS		=	-L$(MLXDIR) -lmlx -framework OpenGL -framework Cocoa -framework AppKit

LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

all:	${NAME}

%.o		:	%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS} ${LIBFT} ${MLX}
	$(CC) ${CFLAGS} ${OBJS} $(LIBFT) $(LIBS) -o ${NAME}

${MLX}	:
	make -C ${MLXDIR}

${LIBFT}:
	make -C ${LIBFT_DIR}

clean	:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean	:	clean
	rm -f ${NAME}
	make -C ${MLXDIR} clean
	make -C ${LIBFT_DIR} fclean

re		: fclean all

.PHONY	: all clean fclean re
