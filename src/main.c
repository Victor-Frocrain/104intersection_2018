/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void read_help(void)
{
    int fd = open("README", O_RDONLY);
    char *buff = malloc(sizeof(char) * 500);

    if (buff == NULL)
        exit(MY_EXIT_SUCCESS);
    memset(buff, 0, 500);
    read(fd, buff, 415);
    printf("%s\n", buff);
    free(buff);
    close(fd);
}

int check_chars(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] != '.' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
            return (MY_EXIT_ERROR);
        else if ((str[i] == '.' || str[i] == '-') && !str[i + 1])
            return (MY_EXIT_ERROR);
        else if ((str[i] == '.' || str[i] == '-') && str[i + 1] &&
                 (str[i + 1] < '0' || str[i + 1] > '9'))
            return (MY_EXIT_ERROR);
    }
    if (i == 0)
        return (MY_EXIT_ERROR);
    return (MY_EXIT_SUCCESS);
}

bool parse_errors(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        read_help();
        return (true);
    }
    else if (ac != 9)
        return (true);
    for (int i = 1; av[i]; i++)
        if (check_chars(av[i]) == 84)
            return (true);
    if (strtod(av[8], NULL) <= 0)
        return (true);
    return (false);
}

int main(int ac, char **av)
{
    if (parse_errors(ac, av))
        return (MY_EXIT_ERROR);
    if (intersect(av) == 84)
        return (MY_EXIT_ERROR);
    return (MY_EXIT_SUCCESS);
}
