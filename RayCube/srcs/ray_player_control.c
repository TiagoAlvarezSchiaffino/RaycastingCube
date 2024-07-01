/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_player_control.c                                   		          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/26 07:25:06 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 10:43:52 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static int	collision(t_gm *gm, t_dvct pos)
{
	t_ivct	map_pos;

	map_pos.x = (int)(round(pos.x));
	map_pos.y = (int)(round(pos.y));
	if (map_pos.x >= 0 && map_pos.x < gm->map.size.x
		&& map_pos.y >= 0 && map_pos.y < gm->map.size.y)
	{
		if (gm->map.map[map_pos.y][map_pos.x] == '1')
			return (1);
		if (gm->map.map[map_pos.y][map_pos.x] == 'D'
			&& gm->map.door_state == D_CLOSE)
			return (1);
	}
	return (0);
}

static int	check_each_step(t_gm *gm, int ver, double rad, int res)
{
	t_dvct	check;
	double	step;

	step = 0.01;
	if (ver)
	{
		while (step < PLY_MVSPD)
		{
			check.x = gm->ply.pos.x + (gm->ply.dir.x * step * 2);
			check.y = gm->ply.pos.y + (gm->ply.dir.y * step * 2);
			res += collision(gm, check);
			step += 0.01;
		}
		return (res);
	}
	while (step < PLY_MVSPD)
	{
		check.x = gm->ply.pos.x + (gm->ply.dir.x * cos(rad)
				- gm->ply.dir.y * sin(rad) * (step * 2));
		check.y = gm->ply.pos.y + (gm->ply.dir.y * cos(rad)
				+ gm->ply.dir.x * sin(rad) * (step * 2));
		res += collision(gm, check);
		step += 0.01;
	}
	return (res);
}

void	ray_player_vertical_movement(t_gm *gm, int keycode)
{
	if (keycode == KEY_W && check_each_step(gm, 1, 0, 0) == 0)
	{
		gm->ply.pos.x = gm->ply.pos.x + (gm->ply.dir.x * PLY_MVSPD);
		gm->ply.pos.y = gm->ply.pos.y + (gm->ply.dir.y * PLY_MVSPD);
	}
	else if (keycode == KEY_S && check_each_step(gm, 1, 0, 0) == 0)
	{
		gm->ply.pos.x = gm->ply.pos.x - (gm->ply.dir.x * PLY_MVSPD);
		gm->ply.pos.y = gm->ply.pos.y - (gm->ply.dir.y * PLY_MVSPD);
	}
}

void	ray_player_horizontal_movement(t_gm *gm, int keycode)
{
	double	rad;

	rad = M_PI / 2;
	if (keycode == KEY_A)
		rad = -M_PI / 2;
	if ((keycode == KEY_A || keycode == KEY_D)
		&& check_each_step(gm, 0, rad, 0) == 0)
	{
		gm->ply.pos.x = gm->ply.pos.x + (gm->ply.dir.x * cos(rad)
				- gm->ply.dir.y * sin(rad) * (PLY_MVSPD));
		gm->ply.pos.y = gm->ply.pos.y + (gm->ply.dir.y * cos(rad)
				+ gm->ply.dir.x * sin(rad) * (PLY_MVSPD));
	}
}

void	ray_player_view(t_gm *gm, int keycode)
{
	double	dir_x;
	double	plane_x;
	double	rot_spd;

	rot_spd = -PLY_ROTSPD;
	if (keycode == KEY_RIGHT)
		rot_spd = PLY_ROTSPD;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		dir_x = gm->ply.dir.x;
		gm->ply.dir.x = gm->ply.dir.x * cos(rot_spd)
			- gm->ply.dir.y * sin(rot_spd);
		gm->ply.dir.y = gm->ply.dir.y * cos(rot_spd)
			+ dir_x * sin(rot_spd);
		plane_x = gm->ply.plane.x;
		gm->ply.plane.x = gm->ply.plane.x * cos(rot_spd)
			- gm->ply.plane.y * sin(rot_spd);
		gm->ply.plane.y = gm->ply.plane.y * cos(rot_spd)
			+ plane_x * sin(rot_spd);
	}
}