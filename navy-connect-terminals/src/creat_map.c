/*
** EPITECH PROJECT, 2020
** navy
** File description:
** all game
*/

#include "my.h"
#include "navy.h"

char *init_buffer(char *FILE, char *buff)
{
    int fd = open(FILE, O_RDONLY);
    int size = 0;
    int len = 0;

    buff = malloc(sizeof(char) + 32);
    while ((len = read(fd, buff + size, 32 - size)) > 0)
        size += len;
    buff[32] = '\0';
    close(fd);
    return (buff);
}

char **init_empty_map(char **map)
{
    map = fill_alphabet(map);
    map = fill_numbers(map);
    map = fill_points(map);
    return (map);
}

char **creat_map(void)
{
    char **map = malloc(sizeof(char *) * (10));

    for (int i = 0; i != 10; i++)
        map[i] = malloc(sizeof(char) + (17));
    map = init_empty_map(map);
    return (map);
}

void print_map(char **map)
{
    for (int i = 0; i != 10; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}
