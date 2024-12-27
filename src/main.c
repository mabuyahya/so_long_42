/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:18:14 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/27 19:50:47 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game game;
	
	check_argvv(argc, argv);
	game.fd = open(argv[1], O_RDONLY);
	geting_map(&game);	
	check_map(&game);
	ft_printf("height ->%d\n width -> %d\n", game.height, game.width);
	set_player_pos(&game);
	can_play(&game);
	





}
