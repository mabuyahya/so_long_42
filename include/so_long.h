/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:46:34 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/31 20:07:45 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ftprintf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# define IMAGE_SIZE 50

typedef struct s_game
{
	int		fd;
	char	**map;
	int		width;
	int		height;
	char	*str;
	int		**empty_map;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*win;
	void	*p_image;
	void	*w_image;
	void	*f_image;
	void	*e_image;
	void	*c_image;
	int		col;
	int		moves;
	int		check_win_fail;
	int		keys[65536];
}			t_game;

int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			loop_handler(t_game *game);
void		count_col(t_game *game);
void		moving_player(t_game *game, int new_player_y, int new_player_x);
void		print_freemap_int(char *str, int **map, int free_flag, int fd);
void		mlx_print_freemap_exit(char *str, char **map, int fl, t_game *game);
void		puting_images(t_game *game, int x, int y);
void		print_free_int_exit(char *str, int *to_free, int free_flag, int fd);
void		print_freemap_int_exit(char *str, int **map, int free_flag, int fd);
void		geting_map(t_game *game);
void		check_argvv(int argc, char **agv);
void		print_free_exit(char *str, char *to_free, int free_flag, int fd);
void		print_freemap_exit(char *str, char **to_free, int free_flag,
				int fd);
void		empty_line(t_game *game);
void		destroy_win_images(t_game *game);
void		check_valid_chars(t_game *game);
void		check_shap(t_game *game);
void		check_map(t_game *game);
void		check_closeness(t_game *game);
int			check_ones(char *str);
int			last_char_i(char *str);
void		check_chars_num(t_game *game);
void		check_c_num(t_game *game);
void		check_p_num(t_game *game);
void		check_e_num(t_game *game);
void		can_play(t_game *game);
void		print_freemap(char *str, char **to_free, int free_flag, int fd);
void		set_player_pos(t_game *game);
void		images_to_window(t_game *game);
void		loding_images(t_game *game);
#endif
