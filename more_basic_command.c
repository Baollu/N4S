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

char *get_info_lidar(void)
{
    char *str = NULL;
    size_t len = 0;

    dprintf(1, "GET_INFO_LIDAR\n");
    getline(&str, &len, stdin);
    check_finished(str);
    return str;
}

char *get_current_wheels(void)
{
    char *str = NULL;
    size_t len = 0;

    dprintf(1, "GET_CURRENT_WHEELS\n");
    getline(&str, &len, stdin);
    check_finished(str);
    return str;
}

float get_wheel_angle(void)
{
    char *str = get_current_wheels();
    char **splitted_str = my_split(str, ':');

    return (float)atof(splitted_str[3]);
}

char *wheel_dir(float nbr)
{
    char *str = NULL;
    size_t len = 0;

    dprintf(1, "WHEELS_DIR:%f\n", nbr);
    getline(&str, &len, stdin);
    check_finished(str);
    return str;
}
