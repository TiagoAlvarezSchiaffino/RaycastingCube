/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_door.c                                        		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/07/01 08:33:49 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 09:41:35 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	fade_door(t_gm *gm)
{
	int		trans;
	t_dvct	px;
	int		pixel;

	trans = gm->win.frame * 255 / DOOR_SPD;
	px.y = -1;
	while (++px.y < gm->map.d_img.size.y)
	{
		px.x = -1;
		while (++px.x < gm->map.d_img.size.x)
		{
			pixel = (px.y * gm->map.d_img.sl) + (px.x * 4);
			if (gm->map.d_img.end == 1)
				gm->map.d_img.addr[pixel + 0] = trans;
			else if (gm->map.d_img.end == 0)
				gm->map.d_img.addr[pixel + 3] = trans;
		}
	}
}

static void	change_char(t_gm *gm, char from, char to)
{
	t_ivct	pos;

	pos.y = -1;
	while (++pos.y < gm->map.size.y)
	{
		pos.x = -1;
		while (++pos.x < gm->map.size.x)
		{
			if (gm->map.map[pos.y][pos.x] == from)
				gm->map.map[pos.y][pos.x] = to;
		}
	}
}

void	ray_update_door(t_gm *gm)
{
	static int	playback = 1;

	if (gm->win.playing == 0)
		return ;
	if (gm->map.door_state == D_OPEN)
		change_char(gm, 'X', 'D');
	gm->win.frame += playback;
	fade_door(gm);
	if (gm->win.frame >= DOOR_SPD || gm->win.frame <= 0)
	{
		if (gm->map.door_state == D_CLOSE)
			change_char(gm, 'D', 'X');
		gm->win.playing = 0;
		playback *= -1;
	}
	gm->map.door_state = gm->map.door_state == D_OPEN;
}

void	ray_door_state(t_gm *gm, int keycode)
{
	if (keycode != KEY_E)
		return ;
	gm->win.playing = 1;
}