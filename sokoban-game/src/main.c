/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** main funciton
*/

#include "soko.h"
#include <curses.h>

int launch_game(soko_t *n);

void helper(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n");
    my_putstr("     map  file representing the warhouse map, containing");
    my_putstr(" '#' for walls,\n\t  ");
    my_putstr("'P' for the player, 'X' for boxes and ");
    my_putstr("'O' for storage locations.\n");
    exit(0);
}

char *check_buf(char *buf)
{
    int count_box = 0;
    int count_player = -1;

    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] != 'P' && buf[i] != ' ' && buf[i] != '#')
            if (buf[i] != '\n' && buf[i] != 'O' && buf[i] != 'X')
                return NULL;
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == 'X')
            count_box += 1;
        if (buf[i] == 'O')
            count_box -= 1;
        else if (buf[i] == 'P')
            count_player += 1;
    }
    if (count_player != 0 || count_box != 0)
        exit(84);
    return buf;
}

char *open_map(char *file)
{
    char *buf;
    size_t size;
    int filedes = 0;
    struct stat st;

    if ((filedes = open(file, O_RDONLY)) < 0)
        exit(84);
    if (stat(file, &st) < 0)
        exit(84);
    buf = malloc(sizeof(char) * st.st_size + 1);
    if (read(filedes, buf, st.st_size) < 0)
        exit(84);
    buf[st.st_size] = '\0';
    close(filedes);
    return check_buf(buf);
}

int main(int ac, char **av)
{
    soko_t *n = malloc(sizeof(soko_t));

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        helper();
    else if ((n->file = open_map(av[1])) == NULL) {
        my_put_error("invalid map.\n");
        return 84;
    } else
        return launch_game(n);
}
