SRC			=	main.c init.c utils.c events.c render.c atodbl.c

OBJS		=	${SRC:.c=.o}

CC			=	cc

NAME		=	fractol

CFLAGS		=	-Wall -Wextra -Werror
LIBDIR		=	./minilibx
LIBS		=	-L$(LIBDIR) -lmlx -framework OpenGL -framework Cocoa -framework AppKit
LIBFT_DIR	=	./libft
LIBFT		=	${LIBFT_DIR}/libft.a

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} ${LIBFT}
	$(CC) ${CFLAGS} ${OBJS} $(LIBFT) $(LIBS) -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_DIR}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
