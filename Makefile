# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 01:24:34 by oaboudan          #+#    #+#              #
#    Updated: 2023/04/20 01:40:40 by oaboudan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC		= gcc

# FLAGS	= -Wall -Wextra -Werror

# NAME 	= so_long

# CFILES	= mandatory/ft_printf/ft_printf.c							\
# 		  mandatory/ft_printf/ft_putchar.c							\
# 		  mandatory/ft_printf/ft_putnbr_base_hex.c					\
# 		  mandatory/ft_printf/ft_putnbr_base_x.c					\
# 		  mandatory/ft_printf/ft_putnbr_u.c							\
# 		  mandatory/ft_printf/ft_putnbr.c							\
# 		  mandatory/ft_printf/ft_putstr.c							\
# 		  mandatory/gnl/get_next_line.c								\
# 		  mandatory/gnl/get_next_line_utils.c						\
# 		  mandatory/srcs/check_map.c								\
# 		  mandatory/srcs/check_valid_path.c							\
# 		  mandatory/srcs/move_player.c 								\
# 		  mandatory/srcs/parse_map.c								\
# 		  mandatory/srcs/so_long.c									\
# 		  mandatory/srcs/utils.c									\
# 		  mandatory/map_mlx/clear_dest_iw.c 						\
# 		  mandatory/map_mlx/import_img_mlx.c 						\
# 		  mandatory/map_mlx/render_map.c							\
# 		  mandatory/eroors/errors.c									\
		  
# CFILESB	= bonus/ft_printf/ft_printf.c								\
# 		  bonus/ft_printf/ft_putchar.c								\
# 		  bonus/ft_printf/ft_putnbr_base_hex.c						\
# 		  bonus/ft_printf/ft_putnbr_base_x.c						\
# 		  bonus/ft_printf/ft_putnbr_u.c								\
# 		  bonus/ft_printf/ft_putnbr.c								\
# 		  bonus/ft_printf/ft_putstr.c								\
# 		  bonus/gnl/get_next_line.c									\
# 		  bonus/gnl/get_next_line_utils.c							\
# 		  bonus/srcs/check_map.c									\
# 		  bonus/srcs/check_valid_path.c								\
# 		  bonus/srcs/move_player.c 									\
# 		  bonus/srcs/parse_map.c									\
# 		  bonus/srcs/so_long_bonus.c								\
# 		  bonus/srcs/utils.c										\
# 		  bonus/srcs/utils2.c										\
# 		  bonus/srcs/move_enmy.c									\
# 		  bonus/map_mlx/clear_dest_iw.c 							\
# 		  bonus/map_mlx/import_img_mlx.c 							\
# 		  bonus/map_mlx/render_map.c								\
# 		  bonus/eroors/errors.c										\
# OFILES	= $(CFILES:.c=.o)
# OBJSB = $(CFILESB:.c=.o)

# all:$(NAME)

# bonus:$(NAMEB)


	
# $(NAME) : $(OFILES)
# 	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $(NAME)
# 	@echo "\033[33;1m😎  done making\033[0m"
# 	@echo "\033[4;35m                                                            \n\
# 	██████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗  		\n \
# 	██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝        \n \
# 	███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗       \n \
# 	╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║		\n \
# 	███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝		\n \
# 	╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ 		\n \
#                                                                        	 		\033[0m"
# 	@echo "                                                      \033[97mBy: Oussama Aboudan"

# $(NAMEB): $(OBJSB)
# 	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJSB) -o $(NAMEB)
# 	@echo "███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗     ████████╗"
# 	@echo "██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝     ██╔═══██║"
# 	@echo "███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗    ████████╝"
# 	@echo "╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║    ██╔═══██╗"
# 	@echo "███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝    ████████║"
# 	@echo "╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝     ╚═══════╝"
	
# %.o:%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
	
# clean	:
# 	@rm -rf $(OFILES)
# 	@rm -rf $(OBJSB)
# 	@echo "\033[32m✅  object files removed successfully.\033[0m"

# fclean	: clean
# 	@rm -rf $(NAME)
# 	@rm -rf $(NAMEB)
# 	@echo "\033[32m✅  object files and archive removed successfully.\033[0m"
# 	@echo "\033[33;1m😎  done cleaning\033[0m"

# re		: fclean all

HRED = '\e[1;91m'
NC   = '\e[0m'

NAME = so_long

NAMEB = so_long_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra   
  
LIBRARY = mandatory/includes/so_long.h

LIBRARYB = bonus/includes/so_long_bonus.h

RM = rm -rf

SRC =	mandatory/ft_printf/ft_printf.c							\
		  mandatory/ft_printf/ft_putchar.c							\
		  mandatory/ft_printf/ft_putnbr_base_hex.c					\
		  mandatory/ft_printf/ft_putnbr_base_x.c					\
		  mandatory/ft_printf/ft_putnbr_u.c							\
		  mandatory/ft_printf/ft_putnbr.c							\
		  mandatory/ft_printf/ft_putstr.c							\
		  mandatory/gnl/get_next_line.c								\
		  mandatory/gnl/get_next_line_utils.c						\
		  mandatory/srcs/check_map.c								\
		  mandatory/srcs/check_valid_path.c							\
		  mandatory/srcs/move_player.c 								\
		  mandatory/srcs/parse_map.c								\
		  mandatory/srcs/so_long.c									\
		  mandatory/srcs/utils.c									\
		  mandatory/map_mlx/clear_dest_iw.c 						\
		  mandatory/map_mlx/import_img_mlx.c 						\
		  mandatory/map_mlx/render_map.c							\
		  mandatory/eroors/errors.c	

		
SRCB =	bonus/ft_printf/ft_printf.c								\
		  bonus/ft_printf/ft_putchar.c								\
		  bonus/ft_printf/ft_putnbr_base_hex.c						\
		  bonus/ft_printf/ft_putnbr_base_x.c						\
		  bonus/ft_printf/ft_putnbr_u.c								\
		  bonus/ft_printf/ft_putnbr.c								\
		  bonus/ft_printf/ft_putstr.c								\
		  bonus/gnl/get_next_line.c									\
		  bonus/gnl/get_next_line_utils.c							\
		  bonus/srcs/check_map.c									\
		  bonus/srcs/check_valid_path.c								\
		  bonus/srcs/move_player.c 									\
		  bonus/srcs/parse_map.c									\
		  bonus/srcs/so_long_bonus.c								\
		  bonus/srcs/utils.c										\
		  bonus/srcs/utils2.c										\
		  bonus/srcs/move_enmy.c									\
		  bonus/map_mlx/clear_dest_iw.c 							\
		  bonus/map_mlx/import_img_mlx.c 							\
		  bonus/map_mlx/render_map.c								\
		  bonus/eroors/errors.c										\

OBJS = $(SRC:.c=.o)

OBJSB = $(SRCB:.c=.o)

all:$(NAME)

bonus:$(NAMEB)

$(NAME): $(OBJS) $(LIBRARY)
	@$(CC) $(CFLAGS) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗"
	@echo "██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝"
	@echo "███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗"
	@echo "╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║"
	@echo "███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
	@echo "╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝"

$(NAMEB): $(OBJSB) $(LIBRARYB)
	@$(CC) $(CFLAGS) $(OBJSB) -lmlx -framework OpenGL -framework AppKit -o $(NAMEB)
	@echo "███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗     ████████╗"
	@echo "██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝     ██╔═══██║"
	@echo "███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗    ████████╝"
	@echo "╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║    ██╔═══██╗"
	@echo "███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝    ████████║"
	@echo "╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝     ╚═══════╝"

%.o : %.c	$(LIBRARY) $(LIBRARYB)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJSB)
	@printf ${HRED}"Object files removed successfully 🗑️ \n"$(NC)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAMEB)
	@printf ${HRED}"Executables & Object removed successfully 🗑️\n"$(NC)
	
re: fclean all 
