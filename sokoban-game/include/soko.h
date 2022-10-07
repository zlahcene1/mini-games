/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** header
*/

#ifndef SOKO_H_
#define SOKO_H_

/*******************HEADERZ***************/

#include "my.h"
#include "struct.h"

/******************BOOLEAN**************/

typedef enum
{
    false,
    true
}my_bool;

/*****************ALL PRINTS***************/

void print_game(soko_t *n);
void start_game(void);
void print_win_los(int win);
void print_quit(void);

/*****************KEY MANGER***************/

int *find_player(char **map);
void p_moves(soko_t *n);
void move_down(soko_t *n, int *pos);
void move_up(soko_t *n, int *pos);
void move_right(soko_t *n, int *pos);
void move_left(soko_t *n, int *pos);

/************STORAGE MANAGER**************/

void count_box(soko_t *n);
int **save_box_place(soko_t *n);
void replace_boxes(soko_t *n);

/*****************FUNCTION****************/

int count_map(char **map);
int launch_game(soko_t *n);
void map_always_loos(soko_t *n);
my_bool loos(soko_t *n, int i, int j);
my_bool checker(soko_t *n);

#endif
