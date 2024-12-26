/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:25:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/25 18:44:21 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map)
{
	check_shap(map);
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
