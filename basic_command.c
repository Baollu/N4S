/*
** EPITECH PROJECT, 2024
** main
** File description:
** main template
*/

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "my.h"
#include "my_macro.h"

char *start_simulation(void)
{
    char *str = NULL;
    size_t len = 0;

    dprintf(1, "START_SIMULATION\n");
    if (getline(&str, &len, stdin) == -1)
        return NULL;
    check_finished(str);
    return str;
}

char *stop_simulation(void)
{
    char *str = NULL;
    size_t len = 0;

    dprintf(1, "STOP_SIMULATION\n");
    if (getline(&str, &len, stdin) == -1)
        return NULL;
    check_finished(str);
    return str;
}

char *cycle_wait(int nbr)
{
    char *str = NULL;
    size_t len = 0;

    dprintf(1, "CYCLE_WAIT:%d\n", nbr);
    if (getline(&str, &len, stdin) == -1)
        return NULL;
    check_finished(str);
    return str;
}

char *set_speed(float nbr)
{
    char *str = NULL;
    size_t len = 0;

    if (nbr >= 0){
        dprintf(1, "CAR_FORWARD:%f\n", nbr);
    } else
        dprintf(1, "CAR_BACKWARDS:%f\n", -nbr);
    if (getline(&str, &len, stdin) == -1)
        return NULL;
    check_finished(str);
    return str;
}

void print_error(char *str)
{
    dprintf(2, "%s", str);
}
