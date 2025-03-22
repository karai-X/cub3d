/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:56:01 by karai             #+#    #+#             */
/*   Updated: 2025/03/22 14:29:20 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_all all[1];
	double angle = 46;

	char* grid[] = {
		"1111111",
		"1010101",
		"1000001",
		"1000011",
		"1111111"
	};
	all->map->grid = (char**)malloc(sizeof(char*) * 6);
	for (int i = 0; i<5; i ++)
	{
		all->map->grid[i] = (char*)malloc(sizeof(char) * 10);
		all->map->grid[i] = strdup(grid[i]);
		printf("%s\n", all->map->grid[i]);
	}
	all->player->px = TILE_SIZE * 3 + 16;
	all->player->py = TILE_SIZE * 2 + 16;
	all->map->width = 7;
	all->map->height = 5;
	all->map->wind_width = all->map->width * TILE_SIZE;
	all->map->wind_height = all->map->height * TILE_SIZE;
	all->player->ang = 0;
	all->dPP = (double)(WIND_WIDTH / 2) / tan(cnv_rad(FOV_ANGLE / 2));
	printf("px py %lf %lf\n", all->player->px, all->player->py);
	initialize_window(all);
	img_raycast(all);
	// printf("%lf\n", vert_dist(all, 193));
	// printf("%lf\n", horz_dist(all, 23));
	// for(int i= 0; i < 100; i++)
	// {
	// 	my_mlx_pixel_put(&(all->img), 5+i, 30, 0x00FF0000);
	// }
	// mlx_put_image_to_window(all->mlx, all->mlx_win, all->img.img, 0, 0);
	while(1)
	{

	}
}
