LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

CCFLAGS		=	cc -Wall -Werror -Wextra

%.o			:	%.c
			${CCFLAGS} -c $< -o $@

${LIBFT}	:
			make -C ${LIBFT_DIR}

clean		:
			rm -f __________
			make -C ${LIBFT_DIR} clean

fclean		:	clean
			${MAKE} fclean -C ./libft
			rm -rf ${SERVER} ${CLIENT}

re			:	fclean all

.PHONY		: 	all bonus clean fclean re