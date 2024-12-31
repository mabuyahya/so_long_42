/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:18:14 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/27 22:56:28by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int loop_handler(t_game *game)
{
	 static int frame_counter = 0;
    const int frame_delay = 800;
    
    frame_counter++;
    if (frame_counter < frame_delay)
        return (0);
        
    frame_counter = 0;
		if (game->keys[XK_w])
			moving_player(game, game->player_y - 1, game->player_x);
		if (game->keys[XK_s])
			moving_player(game, game->player_y + 1, game->player_x);
		if (game->keys[XK_a])
			moving_player(game, game->player_y, game->player_x - 1);
		if (game->keys[XK_d])
			moving_player(game, game->player_y, game->player_x + 1);
	return (0);
}
int	x_handler(t_game *game)
{
	ft_printf("Exit Game\n");
	mlx_print_freemap_exit(NULL, game->map, 1 ,game->fd, game);
	return (0);
}

int	esc_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("Exit Game\n");
		mlx_print_freemap_exit(NULL, game->map, 1 ,game->fd, game);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game game;
	
	ft_bzero(&game, sizeof(t_game));
	check_argvv(argc, argv);
	game.fd = open(argv[1], O_RDONLY);
	geting_map(&game);
	check_map(&game);
	count_col(&game);
	set_player_pos(&game);
	can_play(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		mlx_print_freemap_exit("error in mlx init", game.map, 1 ,game.fd, &game);
	game.win = mlx_new_window(game.mlx, game.width * IMAGE_SIZE, game.height * IMAGE_SIZE, "so_long");
	if (!game.win)
		mlx_print_freemap_exit("error in mlx_new_window", game.map, 1 ,game.fd, &game);
	loding_images(&game);
	images_to_window(&game);
	mlx_key_hook(game.win, esc_press, &game);
	mlx_hook(game.win, 17, 0, x_handler, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);
	mlx_loop_hook(game.mlx, loop_handler, &game);
	mlx_loop(game.mlx);	
}
