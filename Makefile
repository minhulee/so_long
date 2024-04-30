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

SRCS_BONUS			=	./src_bonus/main_bonus.c		\
						./src_bonus/event_bonus.c		\
						./src_bonus/render_bonus.c		\
						./src_bonus/re_end_bonus.c		\
						./src_bonus/physic_bonus.c		\
						./src_bonus/update_bonus.c		\
						./src_bonus/detect_bonus.c		\
						./src_bonus/collision_bonus.c	\
						./src_bonus/system_bonus.c		\
						./src_bonus/destroy_bonus.c		\
						./src_bonus/map_bonus.c			\
						./src_bonus/valid_bonus.c		\
						./src_bonus/mload_bonus.c		\
						./src_bonus/mdefine_bonus.c		\
						./src_bonus/bfs_bonus.c			\
						./src_bonus/mrender_bonus.c		\
						./src_bonus/player_bonus.c		\
						./src_bonus/prender_bonus.c		\
						./src_bonus/zombie_bonus.c		\
						./src_bonus/zrender_bonus.c		\
						./src_bonus/sort_bonus.c		\
						./src_bonus/util_bonus.c		\
						./src_bonus/swirl_bonus.c

OBJS_MAND		=		$(SRCS_MAND:.c=.o)
OBJS_BONUS		=		$(SRCS_BONUS:.c=.o)

ifdef FLAG
    OBJS_FILES	=		$(OBJS_BONUS)
else
    OBJS_FILES	=		$(OBJS_MAND)
endif

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

bonus :
	make all FLAG=1

$(NAME) : $(OBJS_FILES)
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

