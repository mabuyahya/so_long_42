/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:35:52 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/27 14:43:02 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ones(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '1')	
			return (0);
	}
	return(1);
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
