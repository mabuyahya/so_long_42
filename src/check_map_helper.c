/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:35:52 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/28 02:26:44 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_freemap(char *str, char **map, int free_flag, int fd)
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

int	check_ones(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '1')
			return (0);
	}
	return (1);
}

void	print_free_int_exit(char *str, int *to_free, int free_flag, int fd)
{
	if (str)
		ft_putendl_fd(str, 2);
	if (free_flag)
		free(to_free);
	if (fd > 0)
		close(fd);
	exit(1);
}

void	check_chars_num(t_game *game)
{
	check_p_num(game);
	check_e_num(game);
	check_c_num(game);
}

int	last_char_i(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}
