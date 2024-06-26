/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray.h                                         		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 08:32:51 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/26 11:02:30 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../libft/srcs/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_M		46
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define EXIT_EVENT	17
# define KD_EVENT	2
# define KEY_PRESS	1
# define EXIT_MASK	0

/* Map settings */
# define WIN_W		1280
# define WIN_H		800
# define MMAP_W		15
# define MMAP_H		15
# define MMAP_PX	15
# define TEXT_W		64
# define TEXT_H		64

/* Player prefs */
# define PLY_MVSPD	0.25
# define PLY_ROTSPD	0.0625

/* Self defined */
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define TBROWN		0x80964B00
# define TGREY		0x80808080
# define TWHITE		0x80FFFFFF
# define TBLACK		0x80000000
# define PI			3.14159265359
# define RAD_90DEG	1.57079632679

/**
 * @brief Double vector struct
 * 
 * @param x X value
 * @param y Y value
 */
typedef struct s_dvct
{
	double	x;
	double	y;
}	t_dvct;

/**
 * @brief Int vector struct
 * 
 * @param x X value
 * @param y Y value
 */
typedef struct s_ivct
{
	int	x;
	int	y;
}	t_ivct;

/**
 * @brief RGB struct
 * 
 * @param r Red value
 * @param g Green value
 * @param b Blue value
 * @param hex Hex value converted using RGB
 */
typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				hex;
}	t_rgb;

/**
 * @brief Image struct
 * 
 * @param ref Image reference
 * @param addr Address of image
 * @param bpp Bits per pixel of image
 * @param sl Size line of image
 * @param end Endian of image
 * @param size Image size
 */
typedef struct s_img
{
	void	*ref;
	char	*addr;
	int		bpp;
	int		sl;
	int		end;
	t_ivct	size;
}	t_img;

/**
 * @brief Window struct
 * 
 * @param ref Window reference
 * @param frame Current frame
 * @param size Image size
 */
typedef struct s_win
{
	void	*ref;
	int		frame;
	int		mouse;
	t_ivct	size;
}	t_win;

/**
 * @brief Door struct
 * 
 * @param pos Door position
 * @param next Next node
 */
typedef struct s_door
{
	t_ivct			pos;
	struct s_door	*next;
}	t_door;

/**
 * @brief Map struct
 * 
 * @param c_rgb Ceiling RGB values
 * @param f_rgb Floor RGB values
 * @param n_img North wall texture
 * @param e_img East wall texture
 * @param s_img South wall texture
 * @param w_img West wall texture
 * @param d_img Door texture
 * @param main Main image of the map
 * @param mini Minimap image of the map taken from main
 * @param door Door linked list
 * @param map Map array to be rendered in 2D
 * @param map_in Map array taken from file in 2D 
 * @param size Map size
 */
typedef struct s_map
{
	t_rgb	c_rgb;
	t_rgb	f_rgb;
	t_img	n_img;
	t_img	e_img;
	t_img	s_img;
	t_img	w_img;
	t_img	d_img;
	t_img	*main;
	t_img	*mini;
	t_list	*door;
	char	**map;
	char	**map_in;
	t_ivct	size;
	t_img	test;
}	t_map;

/**
 * @brief Player struct
 * 
 * @param e_dir Direction player is facing at in enum
 * @param dir Vector direction of where the player is facing
 * @param c_dir Constant vector direction of where the player is facing
 * @param pos Position of the player on the map
 * @param plane	View plane of the player
 */
typedef struct s_ply
{
	enum
	{
		NOTSET,
		NORTH,
		EAST,
		SOUTH,
		WEST
	}	e_dir;
	t_dvct	dir;
	t_dvct	c_dir;
	t_dvct	pos;
	t_dvct	plane;
}	t_ply;

/**
 * @brief Gamemaster struct
 *
 * @param mlx Main mlx reference
 * @param win Window struct
 * @param map Map struct
 * @param ply Player struct
 */
typedef struct s_gm
{
	void	*mlx;
	t_win	win;
	t_map	map;
	t_ply	ply;
}	t_gm;

void	ray_init_gm(t_gm *gm);

void	ray_get_map(t_gm *gm, char *str, int fd);

void	ray_orient_map(t_gm *gm);

void	ray_check_file(t_gm *gm, int ac, char **av);
void	ray_check_element(t_gm *gm, char **av);
void	ray_check_map(t_gm *gm, int x, int y);

void	ray_all_elements_present(t_gm *gm);
int		ray_map_contents_only(char *str);
int		ray_is_all_num(char *str1, char *str2, char *str3);
void	ray_trim_spaces(char *str, int len);
char	*ray_pad_spaces(t_gm *gm, char *str);

int		ray_fail_exit(char *msg, char *details);
int		ray_success_exit(void);

void	ray_hooks(t_gm *gm);

int		ray_display(t_gm *gm);
void	ray_display_minimap(t_gm *gm);

void	ray_color_block(t_gm *gm, t_ivct cur, unsigned int color);
void	ray_copy_pixel(t_gm *gm, int src_pixel, int x, int y);

void	ray_player_vertical_movement(t_gm *gm, int keycode);
void	ray_player_horizontal_movement(t_gm *gm, int keycode);
void	ray_player_view(t_gm *gm, int keycode);
void	ray_mouse_state(t_gm *gm, int keycode);
void	ray_mouse_control(t_gm *gm);

// Temp (TO DELETE)
void	print_ll(t_list **list);
void	print_da(char **array);
void	print_dl(t_list **list);

#endif