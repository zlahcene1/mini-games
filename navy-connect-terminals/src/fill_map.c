/*
** EPITECH PROJECT, 2020
** navy
** File description:
** fill map
*/

#include "my.h"
#include "navy.h"

char **fill_points(char **map)
{
    for (int i = 2; i < 10; i++) {
        for (int j = 2, count = 0; count != 8; j += 2, count++) {
            map[i][j] = '.';
            map[i][j + 1] = ' ';
        }
        map[i][16] = '.';
        map[i][17] = '\0';
    }
    return (map);
}

char **fill_alphabet(char **map)
{
    map[0][0] = ' ';
    map[0][1] = '|';
    map[1][0] = '-';
    map[1][1] = '+';
    for (int i = 2, c = 'A'; i < 16; i += 2, c++) {
        map[0][i] = c;
        map[0][i + 1] = ' ';
    }
    map[0][16] = 'H';
    map[0][17] = '\0';
    for (int i = 2; i != 17; i++)
        map[1][i] = '-';
    return (map);
}

char **fill_numbers(char **map)
{
    for (int i = 2, nb = '1'; i < 10; i++, nb++) {
        map[i][0] = nb;
        map[i][1] = '|';
    }
    return (map);
}
