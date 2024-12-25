/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:41:22 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/24 15:25:22 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_free_exit(char *str,char *to_free, int free_flag)
{
	if (!str)
		ft_putendl_fd(str, 2);
	if (free_flag)
		free(to_free);
	exit(1);
}

void	check_argv(int argc, char **argv)
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
