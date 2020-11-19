/*
** EPITECH PROJECT, 2018
** intersect
** File description:
** intersect
*/

#include "my.h"

void compute_point_vector(coor *p, coor *v, char **av)
{
    int rad = strtod(av[8], NULL);

    p->x = strtof(av[2], NULL);
    p->y = strtof(av[3], NULL);
    p->z = strtof(av[4], NULL);
    v->x = strtof(av[5], NULL);
    v->y = strtof(av[6], NULL);
    v->z = strtof(av[7], NULL);
}

void compute_sphere(char **av)
{
    coor *p = malloc(sizeof(coor));
    coor *v = malloc(sizeof(coor));
    coor *abc = malloc(sizeof(coor));
    float rad = strtof(av[8], NULL);
    float delta = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    float lambda = 0;

    compute_point_vector(p, v, av);
    abc->x = v->x * v->x + v->y * v->y + v->z * v->z;
    abc->y = 2 * ((p->x * v->x) + (p->y * v->y) + (p->z * v->z));
    abc->z = p->x * p->x + p->y * p->y + p->z * p->z - rad * rad;
    printf("Sphere of radius %.0f\n", rad);
    printf("Line passing through the point (%.0f, %.0f, %.0f) \
and parallel to the vector (%.0f, %.0f, %.0f)\n", p->x, p->y, p->z, v->x, v->y, v->z);
    delta = (abc->y * abc->y) - (4 * abc->x * abc->z);
    if (delta < 0)
        printf("No intersection point.\n");
    else if (delta == 0) {
        lambda = -abc->y / (2 * abc->x);
	x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("1 intersection point:\n(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    else if (delta > 0) {
	lambda = (-abc->y + sqrtf(delta)) / (2 * abc->x);
	x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("2 intersection points:\n(%.3f, %.3f, %.3f)\n", x, y, z);
	lambda = (-abc->y - sqrtf(delta)) / (2 * abc->x);
	x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    free(p);
    free(v);
    free(abc);
}

void compute_cylinder(char **av)
{
    coor *p = malloc(sizeof(coor));
    coor *v = malloc(sizeof(coor));
    coor *abc = malloc(sizeof(coor));
    float rad = strtof(av[8], NULL);
    float delta = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    float lambda = 0;

    compute_point_vector(p, v, av);
    abc->x = v->x * v->x + v->y * v->y;
    abc->y = 2 * ((p->x * v->x) + (p->y * v->y));
    abc->z = p->x * p->x + p->y * p->y - rad * rad;
    printf("Cylinder of radius %.0f\n", rad);
    printf("Line passing through the point (%.0f, %.0f, %.0f) \
and parallel to the vector (%.0f, %.0f, %.0f)\n", p->x, p->y, p->z, v->x, v->y, v->z);
    delta = abc->y * abc->y - 4 * abc->x * abc->z;
    if (delta == 0.00000000) {
        lambda = -abc->y / (2 * abc->x);
        x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("1 intersection point:\n(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    else if (delta > 0.00000000) {
        lambda = (-abc->y + sqrtf(delta)) / (2 * abc->x);
        x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("2 intersection points:\n(%.3f, %.3f, %.3f)\n", x, y, z);
        lambda = (-abc->y - sqrtf(delta)) / (2 * abc->x);
        x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    else if (delta < 0.00000000)
        printf("There is an infinite number of intersection points.\n");
    free(p);
    free(v);
    free(abc);
}

void compute_cone(char **av)
{
    coor *p = malloc(sizeof(coor));
    coor *v = malloc(sizeof(coor));
    coor *abc = malloc(sizeof(coor));
    float rad = strtof(av[8], NULL);
    float delta = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    float lambda = 0;
    float angle = rad * M_PI / 180;

    if (rad < 0 || rad > 90)
        exit(MY_EXIT_ERROR);
    compute_point_vector(p, v, av);
    abc->x = (v->x * v->x + v->y * v->y) - (v->z * v->z * tanf(angle) * tanf(angle));
    abc->y = 2 * ((p->x * v->x + p->y * v->y) - (p->z * v->z * tanf(angle) * tanf(angle)));
    abc->z = (p->x * p->x + p->y * p->y) - (p->z * p->z * tanf(angle) * tanf(angle));
    printf("Cone with a %.0f degree angle\n", rad);
    printf("Line passing through the point (%.0f, %.0f, %.0f) \
and parallel to the vector (%.0f, %.0f, %.0f)\n", p->x, p->y, p->z, v->x, v->y, v->z);
    delta = abc->y * abc->y - (4 * abc->x * abc->z);
    if (delta > 0) {
        lambda = (-abc->y + sqrtf(delta)) / (2 * abc->x);
        x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("2 intersection points:\n(%.3f, %.3f, %.3f)\n", x, y, z);
        lambda = (-abc->y - sqrtf(delta)) / (2 * abc->x);
        x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    else if (delta == 0) {
        lambda = -abc->y / (2 * abc->x);
        x = p->x + lambda * v->x;
        y = p->y + lambda * v->y;
        z = p->z + lambda * v->z;
        printf("1 intersection point:\n(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    else if (delta < 0)
        printf("There is an infinite number of intersection points.\n");
    free(p);
    free(v);
    free(abc);
}

int intersect(char **av)
{
    if (strtod(av[1], NULL) == 1)
        compute_sphere(av);
    else if (strtod(av[1], NULL) == 2)
        compute_cylinder(av);
    else if (strtod(av[1], NULL) == 3)
        compute_cone(av);
    else
        return (MY_EXIT_ERROR);
    return (MY_EXIT_SUCCESS);
}
