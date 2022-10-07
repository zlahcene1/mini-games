/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** core function
*/

#include "soko.h"
#include <curses.h>

void init_game(soko_t *n)
{
    n->end = 0;
    n->map = ft_word_tab(n->file, '\n');
    count_box(n);
    n->b = save_box_place(n);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    n->w = n->n_box;
    map_always_loos(n);
}

void all_free(soko_t *n)
{
    free(n->file);
    for (int i = 0; n->map[i]; i++)
        free(n->map[i]);
    for (int i = 0; i < n->n_box; i++)
        free(n->b[i]);
    free(n);
}

int launch_game(soko_t *n)
{
    int is_a_win = 0;

    init_game(n);
    while (n->end == 0 && n->w > 0) {
        print_game(n);
        p_moves(n);
        replace_boxes(n);
        n->w = n->n_box == 0 ? -1 : n->w;
    }
    is_a_win = n->w == -1 ? 0 : 1;
    print_game(n);
    usleep(100000);
    endwin();
    all_free(n);
    return is_a_win == 0 ? 0 : 1;
}
