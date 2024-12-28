/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:31:36 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/27 23:24:39 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_p_num(t_game *game)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (game->str[i])
	{
		if (game->str[i] == 'P')
			c++;
		i++;
	}
	if (c != 1)
	{
		print_free_exit("should be only one player",game->str, 1, game->fd);
	}
}
void	check_c_num(t_game *game)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (game->str[i])
	{
		if (game->str[i] == 'C')
			c++;
		i++;
	}
	if (c  == 0)
	{
		print_free_exit("should be one 'C'  at least", game->str, 1, game->fd);
	}
}
void	check_e_num(t_game *game)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (game->str[i])
	{
		if (game->str[i] == 'E')
			c++;
		i++;
	}
	if (c != 1)
	 {
		print_free_exit("should be only one exit", game->str, 1, game->fd);
	 }
}
