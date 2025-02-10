#include "../so_long.h"

void initialize_enemies(t_data *data)
{
    int i, j;
    int enemy_index = 0;

    // First pass: Count the number of enemies
    data->enemy_count = 0;
    for (i = 0; i < data->x; i++)
    {
        for (j = 0; j < data->y; j++)
        {
            if (data->ptr[i][j] == 'T') // Assuming 'T' represents an enemy
            {
                data->enemy_count++;
            }
        }
    }

    // Allocate memory for enemies
    if (data->enemy_count > 0)
    {
        data->enemies = malloc(data->enemy_count * sizeof(t_enemy));
        if (!data->enemies)
        {
            perror("Failed to allocate memory for enemies");
            exit(EXIT_FAILURE);
        }
    }

    // Second pass: Initialize enemy positions
    for (i = 0; i < data->x; i++)
    {
        for (j = 0; j < data->y; j++)
        {
            if (data->ptr[i][j] == 'T') // Assuming 'T' represents an enemy
            {
                data->enemies[enemy_index].x = j;
                data->enemies[enemy_index].y = i;
                data->enemies[enemy_index].direction = 1; // Initial direction (right)
                enemy_index++;
            }
        }
    }
}
