#include "cub3d.h"

void	put_1line(t_all *all, int i, double wallStripHeight, long long color)
{
	int	j;
	int	stop;

	j = WIND_HEIGHT / 2 - ceil(wallStripHeight) / 2;
	if (j < 0)
		j = 0;
	stop = ceil(wallStripHeight) + j;
	while (j < WIND_HEIGHT && j < stop)
	{
		my_mlx_pixel_put(&(all->img), i, j, color);
		j += 1;
	}
}

void	put_backview(t_all *all, int floor_color, int ceil_color)
{
	int			i;
	int			j;
	long long	put_color;

	j = 0;
	while (j < WIND_HEIGHT)
	{
		i = 0;
		if (j < WIND_HEIGHT / 2)
		{
			put_color = ceil_color;
		}
		else
			put_color = floor_color;
		while (i < WIND_WIDTH)
		{
			i += 1;
			my_mlx_pixel_put(&(all->img), i, j, put_color);
		}
		j += 1;
	}
}

void	img_raycast(t_all *all)
{
	int		i;
	double	ray_angle;
	double	hd;
	double	vd;
	double	stp_ang;
	double	wallStripHeight;
	double	perpDistance;

	ray_angle = all->player->ang + cnv_rad(FOV_ANGLE / 2);
	if (ray_angle > M_2PI)
		ray_angle -= M_2PI;
	stp_ang = cnv_rad((double)FOV_ANGLE) / (double)WIND_WIDTH;
	i = 0;
	put_backview(all, all->map->floor_color, all->map->ceil_color);
	while (i < WIND_WIDTH)
	{
		// printf("ray angle %lf\n", ray_angle);
		hd = horz_dist(all, ray_angle);
		vd = vert_dist(all, ray_angle);
		// printf("%lf %lf\n", hd, vd);
		if (vd < 0)
		{
			perpDistance = hd * cos(ray_angle - all->player->ang);
			wallStripHeight = ((double)TILE_SIZE / perpDistance) * all->dPP;
			if (0 <= ray_angle && ray_angle < 180)
				put_1line(all, i, wallStripHeight, 0x00FF0000);
			else
				put_1line(all, i, wallStripHeight, 0x0000FF00);
			// printf("1 %lf\n", hd);
		}
		else if (hd < 0)
		{
			perpDistance = vd * cos(ray_angle - all->player->ang);
			wallStripHeight = (TILE_SIZE / perpDistance) * all->dPP;
			if (90 <= ray_angle && ray_angle < 270)
				put_1line(all, i, wallStripHeight, 0x000000FF);
			else
				put_1line(all, i, wallStripHeight, 0x00AAFFFF);
			// printf("2 %lf\n", vd);
		}
		else if (hd <= vd)
		{
			perpDistance = hd * cos(ray_angle - all->player->ang);
			wallStripHeight = ((double)TILE_SIZE / perpDistance) * all->dPP;
			if (0 <= ray_angle && ray_angle < 180)
				put_1line(all, i, wallStripHeight, 0x00FF0000);
			else
				put_1line(all, i, wallStripHeight, 0x0000FF00);
			// printf("1 %lf\n", hd);
		}
		else
		{
			perpDistance = vd * cos(ray_angle - all->player->ang);
			wallStripHeight = (TILE_SIZE / perpDistance) * all->dPP;
			if (90 <= ray_angle && ray_angle < 270)
				put_1line(all, i, wallStripHeight, 0x000000FF);
			else
				put_1line(all, i, wallStripHeight, 0x00AAFFFF);
			// printf("2 %lf\n", vd);
		}
		// printf("wall height %lf\n", wallStripHeight);
		ray_angle -= stp_ang;
		if (ray_angle < 0)
			ray_angle += M_2PI;
		i += 1;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img.img, 0, 0);
}
