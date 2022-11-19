NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDE		= -I include/

FCN			=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

FCN_BONUS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

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
