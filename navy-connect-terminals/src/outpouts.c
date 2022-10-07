/*
** EPITECH PROJECT, 2020
** navy
** File description:
** outpouts
*/

#include "navy.h"

int global;

char **fill_boats(char **map)
{
    map[2][6] = '2';
    map[3][6] = '2';
    map[5][8] = '3';
    map[5][10] = '3';
    map[5][12] = '3';
    map[6][4] = '4';
    map[7][4] = '4';
    map[8][4] = '4';
    map[9][4] = '4';
    map[8][8] = '5';
    map[8][10] = '5';
    map[8][12] = '5';
    map[8][14] = '5';
    map[8][16] = '5';
    return (map);
}

void print_maps(navy_t *n)
{
    my_putstr("my positions:\n");
    print_map(n->map_player);
    my_putstr("\nenemy's positions:\n");
    print_map(n->map_enemy);
    my_putchar('\n');
}

void test(int sig, siginfo_t *p, void *n)
{
    global = p->si_pid;
}

void print_player1(navy_t *n)
{
    struct sigaction player;

    my_putstr("my_pid: ");
    n->pid = getpid();
    my_put_nbr(n->pid);
    my_putstr("\nwaiting for enemy connection...\n");
    player.sa_flags = SA_SIGINFO;
    player.sa_sigaction = test;
    sigaction(SIGUSR2, &player, NULL);
    pause();
    n->enemy_pid = global;
}

void print_player2(navy_t *n, int pid)
{
    my_putstr("my_pid: ");
    n->pid = getpid();
    my_put_nbr(n->pid);
    my_putstr("\nsuccessfully connected\n\n");
    kill(n->enemy_pid, SIGUSR2);
}
