/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:37:20 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/02/02 05:32:46 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_col(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->col = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				game->col++;
			j++;
		}
		i++;
	}
	set_player_pos(game);
}

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	ft_printf("Moves: %s\n", str);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, str);
	free(str);
}

void	moving_player(t_game *game, int new_player_y, int new_player_x)
{
	if (game->map[new_player_y][new_player_x] != '1'
		&& !(game->map[new_player_y][new_player_x] == 'E' && game->col != 0))
	{
		if (game->map[new_player_y][new_player_x] == 'C')
			game->col--;
		if (game->map[new_player_y][new_player_x] == 'E' && game->col == 0)
		{
			mlx_print_freemap_exit("You Win!", game->map, 1, game);
		}
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_player_y][new_player_x] = 'P';
		game->player_x = new_player_x;
		game->player_y = new_player_y;
		game->moves++;
		images_to_window(game);
		display_moves(game);
	}
	if (game->map[new_player_y][new_player_x] == 'E' && game->col != 0)
	{
		ft_printf("You need to collect all the spiders first!\n");
	}
}
