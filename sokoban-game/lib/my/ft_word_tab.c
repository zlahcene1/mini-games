/*
** EPITECH PROJECT, 2021
** mysh1
** File description:
** creat an array with a simple string
*/

#include <stdlib.h>

int my_strlen(char *str);

int count_char(char *str, int index, char c)
{
    int counter = 0;

    for (index; str[index] != c && str[index] != '\0'; index++, counter++);
    return counter;
}

int ft_count_string(char *str, char c)
{
    int count_s = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count_s++;
    return count_s;
}

char **ft_word_tab(char *str, char c)
{
    char **tab = NULL;
    int  count_s = ft_count_string(str, c);
    int count_c = 0;
    int x = 0;

    tab = malloc(sizeof(char *) * (count_s + 1));
    for (int i = 0, y = 0; x < count_s; x++, i++) {
        count_c = count_char(str, i, c);
        tab[x] = malloc(sizeof(char) * (count_c + 1));
        for (y = 0; str[i] != c && str[i] != '\0'; i++, y++)
            tab[x][y] = str[i];
        tab[x][y] = '\0';
    }
    tab[x] = NULL;
    return (tab);
}
