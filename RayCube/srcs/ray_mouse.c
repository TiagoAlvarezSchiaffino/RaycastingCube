/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_mouse.c                                   		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/26 07:22:18 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/26 07:24:57 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_mouse_control(t_gm *gm)
{
	t_ivct	ms;
	double	ratio;
	double	angle;

	mlx_mouse_get_pos(gm->win.ref, &ms.x, &ms.y);
	if (ms.x == WIN_W - 1)
		mlx_mouse_move(gm->win.ref, 0, WIN_H / 2);
	else if (ms.x == 0)
		mlx_mouse_move(gm->win.ref, WIN_W, WIN_H / 2);
	else
		mlx_mouse_move(gm->win.ref, ms.x, WIN_H / 2);
	ratio = ms.x / (double)WIN_W;
	angle = (PI * ratio * 2) - PI;
	gm->ply.dir.x = gm->ply.c_dir.x * cos(angle) + gm->ply.c_dir.y * sin(angle);
	gm->ply.dir.y = gm->ply.c_dir.y * cos(angle) - gm->ply.c_dir.x * sin(angle);
	gm->ply.plane.x = gm->ply.dir.y;
	gm->ply.plane.y = -gm->ply.dir.x;
}

void	ray_mouse_state(t_gm *gm, int keycode)
{
	if (keycode == KEY_M)
	{
		if (gm->win.mouse == 0)
			mlx_mouse_show();
		else if (gm->win.mouse)
			mlx_mouse_hide();
		gm->win.mouse = gm->win.mouse == 0;
	}
}