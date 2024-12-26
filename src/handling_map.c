/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:25:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/26 15:06:39 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map)
{
	check_shap(map);
	check_closeness(map);
	flood_fill(map);
}
void	empty_line(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			print_free_exit("empty line in the map", str, 1);	
		}
		i++;
	}
}

void	check_valid_chars(char *str)	
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'E' 
				&& str[i] != 'P' && str[i] != 'C' && str[i] != '\n')
		{
			print_free_exit("invalid char in the map", str, 1);		
		}
	}
}

void	check_shap(char **map)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	j = 0;
	while (map[0][j])
		j++;
	temp = j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		if (j != temp)
		{
			print_freemap_exit("not a good shap", map, 1);
		}
		i++;
	}
}

void	check_closeness(char **map)
{
	int	i;
	int	last_row;

	i = 0;
	while (map[i])
		i++;
	last_row = i - 1;
	i = -1;
	if(!check_ones(map[0]) && !check_ones(map[last_row]))
		print_freemap_exit("the map is not close1", map, 1);
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][last_char_i(map[i])] != '1')
			print_freemap_exit("the map is not close", map, 1);

	}
}
