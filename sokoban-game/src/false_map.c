/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** specific case of map
*/

#include "soko.h"

int **alloc_my_tab(soko_t *n, int **stock, char c)
{
    int idx = 0;

    for (int i = 0, idx = 0; n->map[i]; i++)
        for (int j = 0; n->map[i][j]; j++)
            if (n->map[i][j] == c) {
                stock = malloc(sizeof(int *) * (idx + 1));
                stock[idx] = NULL;
                idx++;
            }
    return stock;
}

void map_always_loos(soko_t *n)
{
    int **stock = alloc_my_tab(n, stock, 'X');
    int idx = 0;

    for (int i = 0; n->map[i]; i++) {
        for (int j = 0; n->map[i][j]; j++) {
            if (n->map[i][j] == 'X') {
                stock[idx] = malloc(sizeof(int) + 2);
                stock[idx][0] = i;
                stock[idx][1] = j;
                idx++;
            }
        }
    }
    for (int i = 0; i < idx; i++)
        if (loos(n, stock[i][0], stock[i][1])) {
            n->w -= 1;
            free(stock);
        }
}
