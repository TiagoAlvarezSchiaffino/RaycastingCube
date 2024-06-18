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
/*   Updated: 2024/06/18 08:46:26 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../libft/srcs/libft.h"
# include <stdio.h>
# include <mlx.h>

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define EXIT_EVENT	17
# define EXIT_MASK	0

/* Player prefs */
# define WIN_H		1280
# define WIN_W		800

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
 * @param r red value
 * @param g green value
 * @param b blue value
 * @param hex hex value converted using RGB
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
 * @param size Image size
 */
typedef struct s_img
{
	void	*ref;
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
 * @param door Door linked list
 * @param map Map array in 2D
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
	t_list	*door;
	char	**map;
	t_ivct	size;
}	t_map;

/**
 * @brief Player struct
 * 
 * @param e_dir Direction player is facing at in enum
 * @param dir Vector direction of where the player facing
 * @param pos Position of the player on the map
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
	t_dvct	pos;
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

int		ray_user_input(int keycode, t_gm *gm);

// Temp (TO DELETE)
void	print_ll(t_list **list);
void	print_da(char **array);
void	print_dl(t_list **list);

#endif