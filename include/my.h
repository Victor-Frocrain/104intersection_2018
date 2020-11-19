/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <math.h>

#ifndef MY_H_
#define MY_H_
#define MY_EXIT_ERROR (84)
#define MY_EXIT_SUCCESS (0)

struct coordinates_t {
    float x;
    float y;
    float z;
};

typedef struct coordinates_t coor;

int intersect(char **av);

#endif /* MY_H_ */
