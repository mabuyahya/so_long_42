/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:25:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/31 18:16:15 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_game *game)
{
	check_shap(game);
	check_closeness(game);
}

void	empty_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->str[i])
	{
		if (game->str[i] == '\n' && game->str[i - 1] == '\n')
		{
			print_free_exit("empty line in the map", game->str, 1, game->fd);
		}
		i++;
	}
}

void	check_valid_chars(t_game *game)
{
	int	i;

	i = -1;
	while (game->str[++i])
	{
		if ((game->str[i] != '0') && (game->str[i] != '1')
			&& (game->str[i] != 'E') && (game->str[i] != 'P')
			&& (game->str[i] != 'C') && (game->str[i] != '\n'))
		{
			print_free_exit("invalid char in the map", game->str, 1, game->fd);
		}
	}
}

void	check_shap(t_game *game)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	j = 0;
	while (game->map[0][j])
		j++;
	temp = j;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != temp)
		{
			print_freemap_exit("not a good shap", game->map, 1, game->fd);
		}
		i++;
	}
	game->width = j;
	game->height = i;
}

void	check_closeness(t_game *game)
{
	int	i;
	int	last_row;

	i = 0;
	while (game->map[i])
		i++;
	last_row = i - 1;
	i = -1;
	if (!check_ones(game->map[0]) && !check_ones(game->map[last_row]))
	{
		print_freemap_exit("the map is not close1", game->map, 1, game->fd);
	}
	while (game->map[++i])
	{
		if (game->map[i][0] != '1'
			|| game->map[i][last_char_i(game->map[i])] != '1')
		{
			print_freemap_exit("the map is not close", game->map, 1, game->fd);
		}
	}
}
