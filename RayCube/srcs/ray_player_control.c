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
/*   Updated: 2024/06/28 07:21:51 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static int	collision(t_gm *gm, t_dvct pos, double pad)
{
	t_ivct	map_pos;

	map_pos.x = (int)(pos.x + pad);
	map_pos.y = (int)(pos.y + pad);
	if (map_pos.x >= 0 && map_pos.x < gm->map.size.x
		&& map_pos.y >= 0 && map_pos.y < gm->map.size.y)
	{
		if (gm->map.map[map_pos.y][map_pos.x] == '1')
			return (1);
	}
	return (0);
}

void	ray_player_vertical_movement(t_gm *gm, int keycode)
{
	t_dvct	new;

	if (keycode == KEY_W)
	{
		new.x = gm->ply.pos.x + (gm->ply.dir.x * (PLY_MVSPD));
		new.y = gm->ply.pos.y + (gm->ply.dir.y * (PLY_MVSPD));
		if (collision(gm, new, PLY_NEGCOL) == 0)
		{
			gm->ply.pos.x = new.x;
			gm->ply.pos.y = new.y;
		}
	}
	else if (keycode == KEY_S)
	{
		new.x = gm->ply.pos.x - (gm->ply.dir.x * (PLY_MVSPD));
		new.y = gm->ply.pos.y - (gm->ply.dir.y * (PLY_MVSPD));
		if (collision(gm, new, PLY_POSCOL) == 0)
		{
			gm->ply.pos.x = new.x;
			gm->ply.pos.y = new.y;
		}
	}
}

void	ray_player_horizontal_movement(t_gm *gm, int keycode)
{
	double	rad;
	t_dvct	new;

	rad = RAD_90DEG;
	if (keycode == KEY_D)
		rad = -RAD_90DEG;
	if (keycode == KEY_A || keycode == KEY_D)
	{
		new.x = gm->ply.pos.x + (gm->ply.dir.x * cos(rad)
				- gm->ply.dir.y * sin(rad) * (PLY_MVSPD));
		new.y = gm->ply.pos.y + (gm->ply.dir.y * cos(rad)
				+ gm->ply.dir.x * sin(rad) * (PLY_MVSPD));
		if (keycode == KEY_A && collision(gm, new, PLY_POSCOL) == 0)
		{
			gm->ply.pos.x = new.x;
			gm->ply.pos.y = new.y;
		}
		else if (keycode == KEY_D && collision(gm, new, PLY_NEGCOL) == 0)
		{
			gm->ply.pos.x = new.x;
			gm->ply.pos.y = new.y;
		}
	}
}

void	ray_player_view(t_gm *gm, int keycode)
{
	double	dir_x;
	double	plane_x;
	double	rot_spd;

	rot_spd = -PLY_ROTSPD;
	if (keycode == KEY_LEFT)
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