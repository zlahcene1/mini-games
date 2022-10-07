/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** keyboard input
*/

#include "soko.h"
#include <curses.h>

void specific_case(int input, soko_t *n)
{
    switch (input) {
    case 27:
        n->end = -1;
        break;
    case ' ':
        launch_game(n);
        break;
    }
}

void p_moves(soko_t *n)
{
    int input = wgetch(stdscr);
    int *p_pos = find_player(n->map);

    switch (input) {
    case KEY_DOWN:
        move_down(n, p_pos);
        break;
    case KEY_UP:
        move_up(n, p_pos);
        break;
    case KEY_LEFT:
        move_left(n, p_pos);
        break;
    case KEY_RIGHT:
        move_right(n, p_pos);
        break;
    }
    specific_case(input, n);
    free(p_pos);
}
