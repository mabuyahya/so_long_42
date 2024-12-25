/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:18:14 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/24 15:34:16 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int	fd;
	//char	**man;
	//char	**str;
	check_argv(argc, argv);
	fd = open(argv[1], O_RDONLY);
	geting_map(fd);









}
