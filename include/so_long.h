#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>

char	**geting_map(int  fd);
void	check_argvv(int	argc, char **agv);
void    print_free_exit(char *str,char *to_free, int free_flag);
void    print_freemap_exit(char *str,char **to_free, int free_flag);
void	empty_line(char *str);
void    check_valid_chars(char *str);
void	check_shap(char **map);
void	check_map(char **map);
#endif
