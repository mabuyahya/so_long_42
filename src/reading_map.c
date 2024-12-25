/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:42:07 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/24 18:42:21 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*reading_file(int fd)
{
	char	*line;
	char	*str;
	char	*temp;

	line = get_next_line(fd);
	str = ft_strdup("");
	temp = NULL;
	while (line)
	{
		temp = str;
		str = ft_strjoin(str, line);
		if (!str)
		{		
			print_free_exit("error while reading the file", temp,1);
		}
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	if (str[0] == '\0' || !str)
	{
		print_free_exit("empty map", str,1);
	}
	return (str);
}
void	geting_map(int	fd)
{
	char *str;

	if (fd == -1)
	{
		ft_putendl_fd("error in the file permission or not exist", 2);	
		exit(1);
	}
	str = reading_file(fd);
	printf("%s", str);
	free(str);
}
