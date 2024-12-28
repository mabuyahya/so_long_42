/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map_checking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:42:07 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/27 23:31:53 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	reading_file(t_game *game)
{
	char	*line;
	char	*str;
	char	*temp;

	line = get_next_line(game->fd);
	str = ft_strdup("");
	while (line)
	{
		temp = str;
		str = ft_strjoin(str, line);
		if (!str)
		{		
			print_free_exit("error while reading the file", temp,1, game->fd);
		}
		free(temp);
		free(line);
		line = get_next_line(game->fd);
	}
	if (str[0] == '\0' || !str)
	{
		print_free_exit("empty map", str, 1, game->fd);
	}
	game->str = str;
}
void	geting_map(t_game *game)
{
	if (game->fd == -1)
	{
		ft_putendl_fd("error in the file permission or not exist", 2);
		exit(1);
	}
	reading_file(game);
	empty_line(game);
	check_valid_chars(game);
	check_chars_num(game);
	game->map = ft_split(game->str, '\n');
	free(game->str);
}
