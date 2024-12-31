/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:37:08 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/31 19:59:56 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("Exit Game\n");
		mlx_print_freemap_exit(NULL, game->map, 1, game);
	}
	if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 0;
	return (0);
}
