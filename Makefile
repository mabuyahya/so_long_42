#wanted
NAME = so_long
#compile
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

#dir
LIBFT_DIR = lib/libft
FT_PRINTF_DIR = lib/ftprintf
INC_DIR = include

#file
SRC_FILES = main.c error_handling.c  reading_map.c handling_map2.c handling_map3.c handling_map.c
SRC_FILES_WHIT_PREFIX = $(addprefix src/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES_WHIT_PREFIX:src/%.c=obj/%.o)

#libs
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

#Header
HEADERS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

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
