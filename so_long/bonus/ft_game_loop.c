#include "../so_long.h"

static void ft_update_map(t_data *data, int old_x, int old_y, int new_x, int new_y)
{
    data->ptr[old_y][old_x] = '0'; // Clear the old position
    data->ptr[new_y][new_x] = 'P'; // Set the new position
}
void move_enemy(t_data *data, t_enemy *enemy)
{
    int next_x = enemy->x + enemy->direction;
    char next_pos = data->ptr[enemy->y][next_x]; // Check the position ahead of the enemy

    // Check if the next position is a wall or player
    if (next_pos != '1' && next_pos != 'P')
    {
        // If not a wall or player, move the enemy
        enemy->x = next_x;
    }
    else
    {
        // Change direction if the enemy hits a wall or player
        enemy->direction *= -1;
    }

    // Redraw the enemy at the new position
    ft_put_image(data, enemy->y, enemy->x, 'T'); // 'T' for enemy
}

int game_loop(t_data *data)
{
    static int movement_counter = 0;
    int i;

    // Slow down the movement by using a counter (to control the speed)
    if (movement_counter % 10 == 0)  // Adjust the value (10) to control speed
    {
        // Update hero's position
        if (data->hero_direction_x != 0 || data->hero_direction_y != 0)
        {
            int new_x = data->x_p + data->hero_direction_x;
            int new_y = data->y_p + data->hero_direction_y;
            char next_pos = data->ptr[new_y][new_x];

            if (next_pos != '1') // Check if the next position is not a wall
            {
                // Move the hero
                ft_update_map(data, data->x_p, data->y_p, new_x, new_y);
                data->ptr[data->y_p][data->x_p] = '0';
                data->ptr[new_y][new_x] = 'P';
                data->x_p = new_x;
                data->y_p = new_y;

                // Reset movement direction
                data->hero_direction_x = 0;
                data->hero_direction_y = 0;
            }
        }

        // Update all enemies' positions
        for (i = 0; i < data->enemy_count; i++)
        {
            move_enemy(data, &data->enemies[i]);
        }
    }

    movement_counter++;

    // Redraw the entire map
    ft_drow_map(data);

    // Redraw the hero
    mlx_put_image_to_window(data->mlx, data->win, data->img_hero, data->x_p * IMAGE_SIZE, data->y_p * IMAGE_SIZE);

    // Redraw all enemies
    for (i = 0; i < data->enemy_count; i++)
    {
        ft_put_image(data, data->enemies[i].y, data->enemies[i].x, 'T'); // 'T' for enemy
    }

    return (0);
}