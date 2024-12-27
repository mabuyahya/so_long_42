/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:01:12 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/27 19:58:32 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    malloc_empty_map(t_game *game)
{
    int height;
    int width;
    int i;

    i = -1;
    height = game->height;
    width = game->width;
    game->empty_map = malloc(height * sizeof(int  *) + 1);
    if (game->empty_map)
    {
        print_freemap(NULL, game->map, 1, -1);
        print_free_exit("error in malloc", game->map, 1, game->fd);
    }
    ft_memset(game->empty_map, 1, game->height);
    game->empty[game->height] = NULL;
    while (game->empty_map[++i])
    {
        game->empty[i] = ft_calloc(width, sizeof(int) + 1);
        if (game->empty[i])
        {
            print_freemap(NULL, game->map, 1, -1);
            print_freemap_exit("error in malloc", game->empty_map, 1, game->fd);
        }
    }
}
void    flood_fill(t_game *game, int y, int x)
{
    if (game->map[y][x] == '1' || !(game->empty_map[y][x]))
        return ;
    game->empty_map[y][x] = 1;
    flood_fill(game, x + 1,y);    
    flood_fill(game, x - 1,y);    
    flood_fill(game, x, y + 1);    
    flood_fill(game, x, y - 1);    
}

void    set_player_pos(t_game *game)
{
    int	i;
	int	c;

	c = 0;
	i = 0;
	while (game->map[i][j])
	{
		while (game->map[i][j])
        {
            if (map[i][j] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
            }
        }
	}
}
void	can_play(t_game *game)
{
    int i;
    int j;

    i = -1;
    y = 0;
    malloc_empty_map(game);
    flood_fill(game, game->player_y, game->player_x);
    // while (game->empty_map[++i])
    // {
        // while(game->empty_map[i][j])
        // {
            // ft_printf("%")
            // 
        // }       
    // }
}
