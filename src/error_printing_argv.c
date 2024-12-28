/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:41:22 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/28 00:42:45 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_free_exit(char *str,char *to_free, int free_flag, int	fd)
{
	if (str)
		ft_putendl_fd(str, 2);
	if (free_flag)
		free(to_free);
	if (fd > 0)
		close(fd);
	exit(1);
}
void	print_free(char *str,char *to_free, int free_flag, int	fd)
{
	if (str)
		ft_putendl_fd(str, 2);
	if (free_flag)
		free(to_free);
	if (fd > 0)
		close(fd);
}
void	print_freemap_int_exit(char *str,int **map, int free_flag, int fd)
{
	int	i;

	i = 0;
	if (str)
		ft_putendl_fd(str, 2);
	if (free_flag)
	{
		while(map[i])
		{
			free(map[i]);	
			i++;	
		}
		free(map);
	}
	if (fd >= 0)
		close(fd);
	exit(1);
}
void	print_freemap_exit(char *str,char **map, int free_flag, int fd)
{
	int	i;

	i = 0;
	if (str)
		ft_putendl_fd(str, 2);
	if (free_flag)
	{
		while(map[i])
		{
			free(map[i]);	
			i++;	
		}
		free(map);
	}
	if (fd >= 0)
		close(fd);
	exit(1);
}

void	check_argvv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_putendl_fd("invalid argv number", 2);
		exit(1);
	}	
	while (argv[1][i])
		i++;
	if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' 
			|| argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
	{
		ft_putendl_fd("invalid file extension", 2);
		exit(1);	
	}	
}
