/*
** EPITECH PROJECT, 2020
** navy porject!!!
** File description:
** main function
*/

#include "navy.h"

int check_error(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return -1;
    if (ac == 3 && my_str_isnum(av[1]) == 0)
        return -1;
    return 1;
}

int main(int ac, char **av)
{
    navy_t *n = malloc(sizeof(navy_t));

    if (check_error(ac, av) == -1)
        return (84);
    if (my_strcmp(av[1], "-h\0") == 0) {
        navy_helper();
        return (0);
    } else if (ac == 2)
        print_player1(n);
    else {
        n->enemy_pid = my_getnbr(av[1]);
        print_player2(n, my_getnbr(av[1]));
        init(n);
        print_maps(n);
        wait_enemy(n);
    }
    game(n);
    return (0);
}
