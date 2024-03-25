NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	mapcheck.c \
					mapcheck2.c \
					playercontrols.c \
					mapreading.c \
					graphics.c \
					main.c \
					free.c \
					library/get_next_line/get_next_line.c \
					library/get_next_line/get_next_line_utils.c 

LIBFT_PATH		=	./library/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

PRINTF_PATH		=	./library/printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a
MLXFLAGS		=   -lmlx -lXext -lX11
MINILIBX_PATH	=	./library/minilibx-linux

OBJS = ${SRC:.c=.o}

all:				$(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):			$(LIBFT) $(PRINTF) mlx $(OBJS)
					@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF) $(MLXFLAGS) -L$(MINILIBX_PATH)

$(LIBFT):
					@make -C $(LIBFT_PATH) all

$(PRINTF):
					@make -C $(PRINTF_PATH) all

norm:
					norminette ${SRC} $(LIBFT_PATH) $(PRINTF_PATH)

mlx:
					@make -C $(MINILIBX_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					make -C $(MINILIBX_PATH) clean
					make -C $(PRINTF_PATH) clean
					$(RM) $(OBJS)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					make -C $(PRINTF_PATH) fclean
					$(RM) $(NAME) $(OBJS)

re:					fclean all

.PHONY:				all clean fclean re libft printf