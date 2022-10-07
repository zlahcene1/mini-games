/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** kepos[1]board moves
*/

#include "soko.h"
#include <curses.h>

my_bool checker(soko_t *n);

int *find_player(char **map)
{
    int *pos = malloc(sizeof(int) + 2);

    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == 'P') {
                pos[0] = i;
                pos[1] = j;
                return pos;
            }
    free(pos);
}

void move_down(soko_t *n, int *pos)
{
    if (n->map[pos[0] + 1][pos[1]] == '#')
        return;
    if (n->map[pos[0] + 1][pos[1]] == 'X' && n->map[pos[0] + 2][pos[1]] == '#')
        return;
    if (n->map[pos[0] + 1][pos[1]] == 'X' && n->map[pos[0] + 2][pos[1]] == 'X')
        return;
    else if (n->map[pos[0] + 1][pos[1]] == 'X') {
        n->n_box = n->map[pos[0] + 2][pos[1]] == 'O' ? n->n_box - 1 : n->n_box;
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0]+ 1][pos[1]] = 'P';
        n->map[pos[0] + 2][pos[1]] = 'X';
        n->w = loos(n, pos[0] + 2, pos[1]) && !(checker(n)) ? n->w - 1 : n->w;
    } else {
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0] + 1][pos[1]] = 'P';
    }
}

void move_up(soko_t *n, int *pos)
{
    if (n->map[pos[0] - 1][pos[1]] == '#')
        return;
    if (n->map[pos[0] - 1][pos[1]] == 'X' && n->map[pos[0] - 2][pos[1]] == '#')
        return;
    if (n->map[pos[0] - 1][pos[1]] == 'X' && n->map[pos[0] - 2][pos[1]] == 'X')
        return;
    else if (n->map[pos[0] - 1][pos[1]] == 'X') {
        n->n_box = n->map[pos[0] - 2][pos[1]] == 'O' ? n->n_box - 1 : n->n_box;
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0] - 1][pos[1]] = 'P';
        n->map[pos[0] - 2][pos[1]] = 'X';
        n->w = loos(n, pos[0] - 2, pos[1]) && !(checker(n)) ? n->w - 1 : n->w;
    } else {
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0] - 1][pos[1]] = 'P';
    }
}

void move_left(soko_t *n, int *pos)
{
    if (n->map[pos[0]][pos[1] - 1] == '#')
        return;
    if (n->map[pos[0]][pos[1] - 1] == 'X' && n->map[pos[0]][pos[1] - 2] == '#')
        return;
    if (n->map[pos[0]][pos[1] - 1] == 'X' && n->map[pos[0]][pos[1] - 2] == 'X')
        return;
    else if (n->map[pos[0]][pos[1] - 1] == 'X') {
        n->n_box = n->map[pos[0]][pos[1] - 2] == 'O' ? n->n_box - 1 : n->n_box;
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0]][pos[1] - 1] = 'P';
        n->map[pos[0]][pos[1] - 2] = 'X';
        n->w = loos(n, pos[0], pos[1] - 2) && !(checker(n)) ? n->w - 1 : n->w;
    } else {
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0]][pos[1] - 1] = 'P';
    }
}

void move_right(soko_t *n, int *pos)
{
    if (n->map[pos[0]][pos[1] + 1] == '#')
        return;
    if (n->map[pos[0]][pos[1] + 1] == 'X' && n->map[pos[0]][pos[1] + 2] == '#')
        return;
    if (n->map[pos[0]][pos[1] + 1] == 'X' && n->map[pos[0]][pos[1] + 2] == 'X')
        return;
    else if (n->map[pos[0]][pos[1] + 1] == 'X') {
        n->n_box = n->map[pos[0]][pos[1] + 2] == 'O' ? n->n_box - 1 : n->n_box;
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0]][pos[1] + 1] = 'P';
        n->map[pos[0]][pos[1] + 2] = 'X';
        n->w = loos(n, pos[0], pos[1] + 2) && !(checker(n)) ? n->w - 1 : n->w;
    } else {
        n->map[pos[0]][pos[1]] = ' ';
        n->map[pos[0]][pos[1] + 1] = 'P';
    }
}
