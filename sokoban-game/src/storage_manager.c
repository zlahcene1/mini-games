/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** all function who manage storage
*/

#include "soko.h"

void count_box(soko_t *n)
{
    for (int i = 1; n->map[i]; i++)
        for (int j = 0; n->map[i][j]; j++)
            if (n->map[i][j] == 'O')
                n->n_box += 1;
}

int **save_box_place(soko_t *n)
{
    int idx = 0;
    int **save = malloc(sizeof(int *) * (n->n_box + 1));

    for (; idx < n->n_box; idx++)
        save[idx] = malloc(sizeof(int) * 2);
    for (int i = 0, idx = 0; i < count_map(n->map); i++)
        for (int j = 0; n->map[i][j] != '\0'; j++)
            if (n->map[i][j] == 'O') {
                save[idx][0] = i;
                save[idx][1] = j;
                idx++;
            }
    return save;
}

void replace_boxes(soko_t *n)
{
    for (int i = 0; i < n->n_box; i++)
        if (n->map[n->b[i][0]][n->b[i][1]] == ' ')
            n->map[n->b[i][0]][n->b[i][1]] = 'O';
}
