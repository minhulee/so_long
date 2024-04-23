NAME            =       so_long
CC              =       cc
CFLAGS          =       -Wall -Wextra -Werror
INCLUDE         =       -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

MLX_DIR         =       ./mlx
MLX_ARC			=		./mlx/libmlx.a

PRINTF_DIR		=		lib/ft_printf
PRINTF_ARC		=		lib/ft_printf/libftprintf.a

LIBFT_DIR		=		./lib/libft
LIBFT_ARC		=		./lib/libft/libft.a

SRCS_MAND		=		./src/main.c		\
						./src/event.c		\
						./src/render.c		\
						./src/re_end.c		\
						./src/physic.c		\
						./src/update.c		\
						./src/detect.c		\
						./src/collision.c	\
						./src/system.c		\
						./src/destroy.c		\
						./src/map.c			\
						./src/valid.c		\
						./src/mload.c		\
						./src/mdefine.c		\
						./src/bfs.c			\
						./src/mrender.c		\
						./src/player.c		\
						./src/prender.c		\
						./src/zombie.c		\
						./src/zrender.c		\
						./src/sort.c		\
						./src/util.c		\
						./src/swirl.c		\

OBJS_MAND		=		$(SRCS_MAND:.c=.o)

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

$(NAME) : $(OBJS_MAND)
	@echo $(CURSIVE)$(YELLOW) "      - Making $(NAME) Game -" $(NONE)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_ARC) $(PRINTF_ARC) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "            - Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJS_MAND) $(OBJS_BONUS)
	@echo $(CURSIVE)$(BLUE) "     - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@make clean -C $(MLX_DIR)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(NAME) file -"$(NONE)

re  :
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re

