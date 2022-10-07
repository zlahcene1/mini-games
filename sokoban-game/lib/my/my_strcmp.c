/*
** EPITECH PROJECT, 2020
** kjdks
** File description:
** hgfd
*/

int my_strlen(char *str);

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int tmp = 0;

    while (s1[i]) {
        if (s1[i] == s2[i])
            tmp++;
        i++;
    }
    if (tmp == my_strlen(s1) && tmp == my_strlen(s2))
        return 0;
    else
        return -1;
}
