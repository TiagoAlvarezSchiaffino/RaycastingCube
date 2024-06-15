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
/*   Updated: 2024/06/15 06:09:20 by Tiago                  /_____/ U         */
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
}	t_map;

/* Gamemaster struct*/
typedef struct s_gm
{
	void	*mlx;
	t_win	win;
	t_map	map;
}	t_gm;

void	ray_init_gm(t_gm *gm);

void	ray_check_file(t_gm *gm, int ac, char **av);

void	check_element(t_gm *gm, char **av);

int		ray_fail_exit(char *str);
int		ray_success_exit(void);

void	ray_hooks(t_gm *gm);

#endif