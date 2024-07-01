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
/*   Updated: 2024/07/01 09:52:40 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ray_draw_verline(t_img *img, int i, t_gm *gm)
{
	char	*dest;
	double	y;
	int		color;
	double	factor;

	y = 0;
	factor = ((double)(img->size.y - 1)
			/ (double)(gm->render.d_end - gm->render.d_start));
	while (gm->render.d_start < gm->render.d_end)
	{
		if (gm->render.d_start >= 0 && gm->render.d_start < WIN_H)
		{
			dest = img->addr + ((int)y * img->sl
					+ gm->render.tex_x * (img->bpp / 8));
			color = *(unsigned int *)dest;
			ray_my_mlx_pixel_put(&gm->map.imgw, i, gm->render.d_start, color);
		}
		gm->render.d_start++;
		y = y + factor;
	}
}