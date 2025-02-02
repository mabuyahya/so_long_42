/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:01:12 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/31 18:16:54 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	malloc_empty_map(t_game *game)
{
	int	height;
	int	width;
	int	y;

	y = 0;
	height = game->height;
	width = game->width;
	game->empty_map = malloc((height + 1) * sizeof(int *));
	if (!game->empty_map)
	{
		free(game->empty_map);
		print_freemap_exit("error in malloc", game->map, 1, -1);
	}
	game->empty_map[game->height] = NULL;
	while (y < game->height)
	{
		game->empty_map[y] = ft_calloc(width, sizeof(int) + 1);
		if (!game->empty_map[y])
		{
			print_freemap(NULL, game->map, 1, -1);
			print_freemap_int_exit("error in malloc", game->empty_map, 1,
				game->fd);
		}
		y++;
	}
}

void	check_if_can_play(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] == 'E' || game->map[i][j] == 'C')
				&& !game->empty_map[i][j])
			{
				print_freemap(NULL, game->map, 1, -1);
				print_freemap_int_exit("the game can't be played",
					game->empty_map, 1, game->fd);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->height || x >= game->width)
		return ;
	if (game->map[y][x] == '1' || (game->empty_map[y][x]))
		return ;
	game->empty_map[y][x] = 1;
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
	flood_fill(game, y, x - 1);
	flood_fill(game, y, x + 1);
}

void	set_player_pos(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
		}
	}
}

void	can_play(t_game *game)
{
	malloc_empty_map(game);
	flood_fill(game, game->player_y, game->player_x);
	check_if_can_play(game);
	print_freemap_int(NULL, game->empty_map, 1, -1);
}
