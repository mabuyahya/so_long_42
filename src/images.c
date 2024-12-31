/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:37:57 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/31 15:54:25 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    loding_images(t_game *game)
{
    int width;
    int height;
    game->p_image = mlx_xpm_file_to_image(game->mlx, 
                "g/player.xpm", &width, &height);
    game->c_image = mlx_xpm_file_to_image(game->mlx, 
                "g/collect.xpm", &width, &height);
    game->w_image = mlx_xpm_file_to_image(game->mlx, 
                "g/wall.xpm", &width, &height);
    game->e_image = mlx_xpm_file_to_image(game->mlx, 
                "g/exit.xpm", &width, &height);
    game->f_image = mlx_xpm_file_to_image(game->mlx, 
                "g/floor.xpm", &width, &height);
    if (!game->c_image || !game->f_image 
                || !game->p_image || !game->e_image || !game->w_image)
    {
        mlx_print_freemap_exit("error in mlx_xpm_file_to_image", game->map, 1, game->fd, game);
    }
}
void    images_to_window(t_game *game)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width) 
        {
            puting_images(game, x, y);
            x++;
        }
        y++;
    }
}
void   puting_images(t_game *game, int  x, int  y)
{
    int i;
    void    *temp;
    i = 0;
    if (game->map[y][x] == 'C')
        temp = game->c_image;
    else if (game->map[y][x] == 'P')
        temp = game->p_image;
    else if (game->map[y][x] == 'E')
        temp = game->e_image;
    else if (game->map[y][x] == '0')
        temp = game->f_image;
    else if (game->map[y][x] == '1')
        temp = game->w_image;
    i = mlx_put_image_to_window(game->mlx, game->win, temp, x * IMAGE_SIZE, y * IMAGE_SIZE);
    if (i == -1)
    {    
        mlx_print_freemap_exit("error, in mlx_put_image_to_window", game->map, 1, game->fd, game);
    }
}