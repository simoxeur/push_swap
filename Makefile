NAME	= push_swap

NAME_B	= checker

UTILS_SRC = utils/ft_split.c			utils/ft_strchr.c \
			utils/ft_strlen.c			utils/ft_strjoin.c  \
			utils/ft_substr.c			utils/ft_strdup.c	\
			utils/ft_atoi.c				utils/ft_array_len.c \
			utils/ft_free_arr.c  		utils/join.c	\
			utils/error_msg.c 			utils/ft_strcmp.c 	


SRCS		=	srcs/listing.c			srcs/loading.c		srcs/stackA_moves.c		srcs/stackB_moves.c		\
				srcs/join_args.c		srcs/get_median.c		srcs/shared_moves.c		srcs/moves.c	srcs/free_stack.c

SRCS_MANDATORY = mandatory/push_swap.c	mandatory/parsing.c		mandatory/sort_nbr.c	mandatory/sort_nbr2.c	mandatory/appending.c	mandatory/a_to_b.c	mandatory/b_to_a.c

SRCS_BNS	=   bonus/push_swap_bonus.c		bonus/reading.c		bonus/applicate.c		bonus/check_sort.c	bonus/parsing_bonus.c	bonus/lst_move.c 

gnl			=	bonus/gnl/get_next_line.c	bonus/gnl/get_next_line_utils.c

OBJS	=		${SRCS_MANDATORY:.c=.o}		${SRCS:.c=.o}		${UTILS_SRC:.c=.o}

OBJS_BNS	=	${SRCS_BNS:.c=.o}		${SRCS:.c=.o}		${UTILS_SRC:.c=.o}		${gnl:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%_bonus.o:%_bonus.c  utils/utils.h  bonus/push_swap_bonus.h   bonus/gnl/get_next_line.h  srcs/srcs.h
	$(CC) ${CFLAGS} -c $< -o $@

%.o:%.c  mandatory/push_swap.h  utils/utils.h	srcs/srcs.h
	$(CC) ${CFLAGS} -c $< -o $@

$(NAME): 		${OBJS}
	$(CC) ${OBJS} -o ${NAME}

bonus:		${OBJS_BNS}
	$(CC) ${OBJS_BNS} -o ${NAME_B}

clean:
	rm -f ${OBJS} ${OBJS_BNS}

fclean: 	clean
	rm -f $(NAME) $(NAME_B)

re:		fclean all

.PHONY: all clean fclean re