#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>

typedef struct s_game
{
    int fd;
    char **map;
    int width;
    int height;
    char *str;
    int **empty_map;


}           t_game;
void    geting_map(t_game *game);
void	check_argvv(int	argc, char **agv);
void    print_free_exit(char *str,char *to_free, int free_flag, int fd);
void    print_freemap_exit(char *str,char **to_free, int free_flag, int fd);
void	empty_line(t_game *game);
void    check_valid_chars(t_game *game);
void	check_shap(t_game *game);
void	check_map(t_game *game);
void	check_closeness(t_game *game);
int	check_ones(char *str);	
int	last_char_i(char *str);
void	check_chars_num(t_game *game);
void	check_c_num(t_game *game);
void	check_p_num(t_game *game);
void	check_e_num(t_game *game);
void    can_play(t_game *game);
void    print_freemap(char *str,char **to_free, int free_flag, int fd);
#endif
