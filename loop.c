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

void check_finished(char *str)
{
    char **splitted_str = my_split(str, ':');

    for (int i = 0; splitted_str[i]; i++)
        if (my_strcmp(splitted_str[i], "Track Cleared") == 0)
            stop_simulation();
}

static int *get_dist(void)
{
    char *str = get_info_lidar();
    char **splitted_str = my_split(str, ':');
    int *dist_list = malloc(sizeof(int) * (33));

    for (int i = 0; i < 8; i++){
        dist_list[i] = atoi(splitted_str[i * 4 + 3]);
        dist_list[i] = MIN(dist_list[i], atoi(splitted_str[i * 4 + 4]));
        dist_list[i] = MIN(dist_list[i], atoi(splitted_str[i * 4 + 5]));
        dist_list[i] = MIN(dist_list[i], atoi(splitted_str[i * 4 + 6]));
    }
    return dist_list;
}

static float calc_angle(int *dist)
{
    float index_max = -1;
    int max = -1;

    for (float i = 0; i < 8; i++){
        if (dist[(int)i] > max){
            max = dist[(int)i];
            index_max = i;
        }
    }
    return ((index_max - 4) / 4);
}

int get_index_min(int *dist)
{
    float index_min = -1;
    int min = -1;

    for (float i = 0; i < 8; i++){
        if (dist[(int)i] < min || min == -1){
            min = dist[(int)i];
            index_min = i;
        }
    }
    return index_min;
}

static float cap_angle(float angle)
{
    if (angle > 1)
        angle = 1.0;
    if (angle < -1)
        angle = -1.0;
    return angle;
}

static float choose_dir(int *dist)
{
    float angle = calc_angle(dist);
    int safe_mode = MIN(dist[0], dist[7]) < LIMIT_SAFE;
    int index_min = get_index_min(dist);

    if (safe_mode){
        if (index_min <= 3)
            angle = 1;
        else
            angle = -1;
        set_speed(SPEED_SAFE);
        return angle * MULT_ANGLE_SAFE;
    }
    if (dist[3] + dist[4] > LIMIT_SPEED){
        wheel_dir(0);
        set_speed(SPEED_FAST);
    } else
        set_speed(SPEED);
    angle = cap_angle(angle);
    return angle * MULT_ANGLE;
}

void loop(void)
{
    int *dist = NULL;
    float wheel_angle = 0;

    while (1){
        dist = get_dist();
        wheel_angle = choose_dir(dist);
        wheel_dir(-wheel_angle);
    }
}
