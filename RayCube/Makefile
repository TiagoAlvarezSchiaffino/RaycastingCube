# ************************************************************************** #
#                                                                            #
#                                                                            #
#   Makefile                                                                 #
#                                                                            #
#   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             #
#                                                             / \__          #
#                                                            (    @\___      #
#                                                             /         O    #
#   Created: 2024/06/14 08:21:03 by Tiago                    /   (_____/     #
#   Updated: 2024/06/18 08:45:15 by Tiago                 /_____/ U          #
#                                                                            #
# ************************************************************************** #

NAME		=	raycube
LIBFT		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -Imlx
# CFLAGS		+=	-fsanitize=address -g3
MLXFLAGS	=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS_FILES	=	ray_main \
				ray_hook \
				ray_exit \
				ray_init \
				ray_get_map \
				ray_check_map \
				ray_check_file \
				ray_user_input \
				ray_check_utils \
				ray_check_element \
				temp
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/

all:			
				mkdir -p $(OBJS_DIR)
				make libft
				make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(OBJS) $(MLXFLAGS) -o $(NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all bonus libft clean fclean re