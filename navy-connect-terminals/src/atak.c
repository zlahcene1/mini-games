/*
** EPITECH PROJECT, 2021
** navy
** File description:
** attack / def
*/

#include "navy.h"

void ft(int sig)
{
    pause();
}

void recup_attack(navy_t *n)
{
    struct sigaction receiver;
    int x = 0;
    int y = 0;

    n->x_attak = 0;
    n->y_attak = 0;
    receiver.sa_handler = ft;
    sigaction(SIGUSR1, &receiver, NULL);
    n->x_attak += 1;
    receiver.sa_handler = ft;
    sigaction(SIGUSR2, &receiver, NULL);
    n->y_attak += 1;
}

void send_attack(int x, int y, navy_t *n)
{
    for (int i = 0; i < x; i++) {
        kill(n->enemy_pid, SIGUSR1);
        usleep(1000);
    }
    for (int i = 0; i < y; i++) {
        kill(n->enemy_pid, SIGUSR2);
        usleep(1000);
    }
}

void tanslate_attack(navy_t *n, char *plays)
{
    int y = transform(plays[0]);
    int x = plays[1] - 47;

    if (n->map_player[x][y] != '.') {
        n->map_enemy[x][y] = 'x';
        my_putstr("hit\n\n");
    } else
        my_putstr("missed\n\n");
    send_attack(x, y, n);
}

int do_attack(navy_t *n)
{
    char *plays = NULL;
    size_t size;

    my_putstr("attack: ");
    if (getline(&plays, &size, stdin) <= 0)
        return -1;
    write(1, plays, 2);
    write(1, ": ", 2);
    tanslate_attack(n, plays);
    return 0;
}
