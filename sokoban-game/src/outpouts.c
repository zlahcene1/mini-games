/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** all outpout in ncurses
*/

#include "soko.h"
#include <ncurses.h>

int count_map(char **map)
{
    int i = 0;
    for (; map[i]; i += 1);
    return i;
}

void print_game(soko_t *n)
{
    int x = 0;
    int y = 0;
    int middle_x = 0;

    getmaxyx(stdscr, x, y);
    middle_x = (x / 2) - (count_map(n->map) / 2);
    wclear(stdscr);
    for (int i = 0, z = 0; n->map[i]; i += 1, z += 1)
        mvprintw(middle_x + z, (y - my_strlen(n->map[i]))/ 2, "%s", n->map[i]);
    wrefresh(stdscr);
}

void print_win_los(int win)
{
    int x = 0;
    int y = 0;
    char *msg = win == 0 ? "YOU WIN!!!!" : "YOU LOOSE..:(";

    msg = my_strcat(" (press ESC for quit)", msg);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, x, y);
    wclear(stdscr);
    while (wgetch(stdscr) != 27)
        mvprintw(x / 2, (y - my_strlen(msg)) / 2, "%s", msg);
    wrefresh(stdscr);
    endwin();
}
