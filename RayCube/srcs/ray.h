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
/*   Updated: 2024/06/17 22:17:03 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../libft/srcs/libft.h"
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

/* Vector struct */
typedef struct s_vct
{
	int	x;
	int	y;
}	t_vct;

/* RGB struct */
typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				hex;
}	t_rgb;

/* Image struct */
typedef struct s_img
{
	void	*ref;
	t_vct	size;
}	t_img;

/* Window struct */
typedef struct s_win
{
	void	*ref;
	t_vct	size;
}	t_win;

/* Map struct */
typedef struct s_map
{
	t_rgb	c_rgb;
	t_rgb	f_rgb;
	t_img	n_img;
	t_img	e_img;
	t_img	s_img;
	t_img	w_img;
	char	**map;
	t_vct	size;
}	t_map;

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
	t_vct	pos;
}	t_ply;

/* Gamemaster struct*/
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

int		ray_fail_exit(char *str);
int		ray_success_exit(void);

void	ray_hooks(t_gm *gm);

// Temp (TO DELETE)
void	print_ll(t_list **list);
void	print_da(char **array);

#endif