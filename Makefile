# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 01:24:34 by oaboudan          #+#    #+#              #
#    Updated: 2023/04/17 01:27:49 by oaboudan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

NAME 	= so_long

CFILES	= ft_printf/ft_printf.c							\
		  ft_printf/ft_putchar.c						\
		  ft_printf/ft_putnbr_base_hex.c				\
		  ft_printf/ft_putnbr_base_x.c					\
		  ft_printf/ft_putnbr_u.c						\
		  ft_printf/ft_putnbr.c							\
		  ft_printf/ft_putstr.c							\
		  gnl/get_next_line.c							\
		  gnl/get_next_line_utils.c						\
		  srcs/check_map.c								\
		  srcs/check_valid_path.c						\
		  srcs/move_player.c 							\
		  srcs/parse_map.c								\
		  srcs/so_long.c								\
		  srcs/utils.c									\
		  map_mlx/clear_dest_iw.c 						\
		  map_mlx/import_img_mlx.c 						\
		  map_mlx/render_map.c							\
		  eroors/errors.c
OFILES	= $(CFILES:.c=.o)

all : $(NAME)

	
$(NAME) : $(OFILES)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $(NAME)
	@echo "\033[33;1m😎  done making\033[0m"
	@echo "\033[4;35m                                                            \n\
	██████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗  		\n \
	██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝        \n \
	███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗       \n \
	╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║		\n \
	███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝		\n \
	╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ 		\n \
                                                                       	 		\033[0m"
	@echo "                                                      \033[97mBy: Oussama Aboudan"
	
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	
clean	:
	@rm -rf $(OFILES)
	@echo "\033[32m✅  object files removed successfully.\033[0m"

fclean	: clean
	@rm -rf $(NAME)
	@echo "\033[32m✅  object files and archive removed successfully.\033[0m"
	@echo "\033[33;1m😎  done cleaning\033[0m"

re		: fclean all
