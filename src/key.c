#include "so_long.h"

int key_press(int keycode, t_game *game)
{
    if (keycode >= 0 && keycode < 65536)  // Prevent array overflow
        game->keys[keycode] = 1;
    return (0);
}

int key_release(int keycode, t_game *game)
{
     if (keycode >= 0 && keycode < 65536)  // Prevent array overflow
        game->keys[keycode] = 0;
    return (0);
}
