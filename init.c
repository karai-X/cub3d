/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:54:22 by karai             #+#    #+#             */
/*   Updated: 2025/03/22 19:13:05 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_player(t_player *player)
{
	player->px = TILE_SIZE * 3 + 16;
	player->py = TILE_SIZE * 2 + 16;
	player->ang = cnv_rad(30);
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->moveSpeed = 4.0;
	player->rotSpeed = 3 * ((double)M_PI / 180);
}

void init_map(t_map *map)
{
	map->floor_color = 0x00123456;
	map->ceil_color =  0x0089A211;
}
