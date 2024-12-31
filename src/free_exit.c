/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:17:00 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/31 20:02:02 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_print_freemap_exit(char *str, char **map, int free_flag,
		t_game *game)
{
	int	i;

	i = 0;
	if (str)
		ft_putendl_fd(str, 2);
	if (free_flag)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	close(game->fd);
	destroy_win_images(game);
	exit(1);
}

void	destroy_win_images(t_game *game)
{
	if (game->p_image)
		mlx_destroy_image(game->mlx, game->p_image);
	if (game->w_image)
		mlx_destroy_image(game->mlx, game->w_image);
	if (game->f_image)
		mlx_destroy_image(game->mlx, game->f_image);
	if (game->e_image)
		mlx_destroy_image(game->mlx, game->e_image);
	if (game->c_image)
		mlx_destroy_image(game->mlx, game->c_image);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	print_freemap_int(char *str, int **map, int free_flag, int fd)
{
	int	i;

	i = 0;
	if (str)
		ft_putendl_fd(str, 2);
	if (free_flag)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	if (fd >= 0)
		close(fd);
}
