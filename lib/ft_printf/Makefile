# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 16:35:58 by minhulee          #+#    #+#              #
#    Updated: 2023/12/05 16:40:05 by minhulee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


CC			=	cc
CFLAGS		=	-c -Werror -Wall -Wextra

SRCS_M		=	ft_printf.c \
				read_formats.c \
				print_format.c \
				print_format_c.c \
				print_format_s.c \
				print_format_p.c \
				print_format_di.c \
				print_format_u.c \
				print_format_xX.c \
				print_format_per.c \
				print_without_format.c \
				util_printf.c

SRCS_B		= 	ft_printf_bonus.c \
				read_formats_bonus.c \
				decode_format_bonus.c decode_flags_bonus.c decode_width_bonus.c decode_precision_bonus.c \
				print_format_bonus.c \
				print_sharp_bonus.c print_width_bonus.c print_precision_bonus.c \
				print_format_c_bonus.c \
				print_format_s_bonus.c \
				print_format_p_bonus.c \
				print_format_di_bonus.c \
				print_format_u_bonus.c \
				print_format_xX_bonus.c \
				print_format_per_bonus.c \
				print_without_format_bonus.c \
				util_printf_bonus.c

OBJS_M		=	$(SRCS_M:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

ifdef FLAG
	OBJS = $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

NAME 		=	libftprintf.a

all 		:	$(NAME)

%.o 		:	%.c
				$(CC) $(CFLAGS) $< -o $@

$(NAME)		:	$(OBJS)
				ar cr $@ $^

bonus 		:
				make all FLAG=1

clean		:
				rm -f $(OBJS_M) $(OBJS_B)

fclean		:
				make clean
				rm -f $(NAME)

re			: 
				make fclean
				make all

.PHONY		:	all bonus clean fclean re