/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game management
*/

#include "my.h"
#include "navy.h"
#include "my_struct.h"

void navy_helper(void)
{
    my_putstr("USAGE\n    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid: only for the 2nd player.");
    my_putstr("pid of the first player.\n");
    my_putstr("    navy_positions: file representing the positions");
    my_putstr("of the ships.\n");
}

void init(navy_t *n)
{
    n->map_player = fill_boats(creat_map());
    n->map_enemy = creat_map();
}

int transform(char c)
{
    if (c == 'A')
        return 2;
    else
        return (2 * (c - '@'));
}

void wait_enemy(navy_t *n)
{
    struct sigaction p;

    my_putstr("waiting for enemy's attack...\n");
    recup_attack(n);
    pause();
}

void game(navy_t *n)
{
    init(n);
    while (n->victory_defeat == 0) {
        print_maps(n);
        if (do_attack(n) == -1)
            return;
        wait_enemy(n);
    }
    free(n);
}
