#wanted
NAME = so_long
#compile
CC = cc
CFLAGS = -Wall -Werror -Wextra 

#dir
LIBFT_DIR = lib/libft
FT_PRINTF_DIR = lib/ftprintf
INC_DIR = include

#file
SRC_FILES = check_chars_number.c  check_map_helper.c   	 main.c      reading_map_checking.c \
check_map.c     free_exit.c   images.c   error_printing_argv.c  playable.c  moving_player.c key.c \



SRC_FILES_WHIT_PREFIX = $(addprefix src/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES_WHIT_PREFIX:src/%.c=obj/%.o)

#libs
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -Lminilibx-linux -lmlx -lXext -lX11

#Header
HEADERS = -Iminilibx-linux  -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)  

#rules
all:LIBFT FT_PRINTF $(NAME)
		
$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ_FILES)
		$(CC) $(CFLAGS) $(OBJ_FILES) $(HEADERS) $(LIBS) -o $(NAME)

obj/%.o: src/%.c $(INC_DIR)/so_long.h 
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
LIBFT :
	$(MAKE) -s -C $(LIBFT_DIR)
FT_PRINTF :
	$(MAKE) -s -C $(FT_PRINTF_DIR)

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(FT_PRINTF_DIR) clean
		rm -rf obj

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(FT_PRINTF_DIR) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
