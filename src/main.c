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

int	main(int argc, char *argv[])
{
	t_game game;
	
	ft_bzero(&game, sizeof(t_game));
	check_argvv(argc, argv);
	game.fd = open(argv[1], O_RDONLY);
	geting_map(&game);	
	check_map(&game);
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
	mlx_loop(game.mlx);
	mlx_print_freemap_exit(NULL, game.map, 1 ,game.fd, &game);	
}
