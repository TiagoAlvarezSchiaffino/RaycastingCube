/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_draw.c                                   		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/07/01 09:20:53 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 09:23:49 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_verline(t_img *img, int i, t_gm *gm)
{
	char	*dest;
	double	y;
	int		newcolor;
	double	factor;

	y = 0;
	factor = ((double)(img->size.y - 1)
			/ (double)(gm->render.draw_end - gm->render.draw_start));
	while (gm->render.draw_start < gm->render.draw_end)
	{
		if (gm->render.draw_start >= 0 && gm->render.draw_start < WIN_H)
		{
			dest = img->addr + ((int)y * img->sl
					+ gm->render.tex_x * (img->bpp / 8));
			newcolor = *(unsigned int *)dest;
			my_mlx_pixel_put(&gm->map.imgw, i, gm->render.draw_start, newcolor);
		}
		gm->render.draw_start++;
		y = y + factor;
	}
}