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
#   Updated: 2024/07/01 10:30:29 by Tiago                 /_____/ U          #
#                                                                            #
# ************************************************************************** #

NAME		=	raycube
LIBFT		=	libft/libft.a
MLX			=	mlx/libmlx.a
CC			=	gcc
RM			=	rm -rf
MKDIR		=	mkdir -p
CFLAGS		=	-Wall -Wextra -Werror -Imlx
# CFLAGS		=	-fsanitize=address -g3
MLXFLAGS	=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS_FILES	=	ray_main \
				ray_hook \
				ray_exit \
				ray_init \
				ray_door \
				ray_draw \
				ray_mouse \
				ray_render \
				ray_get_map \
				ray_minimap \
				ray_display \
				ray_check_map \
				ray_check_file \
				ray_renderdoor \
				ray_image_utils \
				ray_check_utils \
				ray_render_utils \
				ray_player_control
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft/
OBJS_DIR	=	objs/

all:			
				$(MKDIR) $(OBJS_DIR)
				make libft
				make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) $(MLXFLAGS) -o $(NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				$(RM) $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus libft clean fclean re