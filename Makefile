NAME		= libftprintf.a

libft		= ./libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDE		= -I ./

FCN			=	ft_printf.c \
				ft_printf_process_csdiupercent.c \
				ft_printf_process_pxX.c \
				ft_printf_libft.c

FCN_BONUS	=

FCNF		= ./

SRC			= $(addprefix ${FCNF}, $(FCN))

SRC_BONUS	= $(addprefix ${FCNF}, $(FCN_BONUS))

OBJ			= ${SRC:.c=.o}

OBJ_BONUS	= ${SRC_BONUS:.c=.o}

RM			= rm -f

.c.o	:
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

all		:	${NAME}

${NAME}	:	${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

bonus	:	${OBJ} ${OBJ_BONUS}
			ar rc ${NAME} ${OBJ} ${OBJ_BONUS}
			ranlib ${NAME}
clean 	:
			${RM} ${OBJ} ${OBJ_BONUS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

so:
			$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRC_BONUS)
			gcc -nostartfiles -shared -o libft.so $(OBJ) ${OBJ_BONUS}

.PHONY	:	all bonus clean fclean re so
