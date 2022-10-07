/*
** EPITECH PROJECT, 2020
** navy
** File description:
** all headerz
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <signal.h>
#include "my_struct.h"
#include "my.h"

/********** MAP FILLED ************/

char **fill_points(char **map);
char **fill_alphabet(char **map);
char **fill_numbers(char **map);
char **creat_map(void);
char *init_buffer(char *FILE, char *buff);
void print_maps(navy_t *n);
char **fill_boats(char **map);

/********** CORE FUNCTION *********/

void wait_enemy(navy_t *n);
void init(navy_t *n);
void game(navy_t *n);

/********** PRINTS ***************/

void print_map(char **map);
void navy_helper(void);
void print_player2(navy_t *n, int PID);
void print_player1(navy_t *n);
void connected(int sigint);

/********* ATTACK SIG ***********/
int transform(char c);
void recup_attack(navy_t *n);
void send_attack(int x, int y, navy_t *n);
void tanslate_attack(navy_t *n, char *plays);
int do_attack(navy_t *n);

#endif
