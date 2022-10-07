/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** all boolean
*/

#include "soko.h"

my_bool loos2(soko_t *n, int i, int j)
{
    if (n->map[i + 1][j] == '#' && n->map[i][j + 1] == '#')
        return true;
    else if (n->map[i + 1][j] == '#' && n->map[i][j - 1] == '#')
        return true;
    else
        return false;
}

my_bool checker(soko_t *n)
{
    for (int i = 0; i < n->n_box; i++)
        if (n->map[n->b[i][0]][n->b[i][1]] == 'X')
            return true;
    return false;
}

my_bool loos(soko_t *n, int i, int j)
{
    if (n->map[i - 1][j] == '#' && n->map[i][j + 1] == '#')
        return true;
    if (n->map[i - 1][j] == '#' && n->map[i][j - 1] == '#')
        return true;
    else if (loos2(n, i, j))
        return true;
    return false;
}
