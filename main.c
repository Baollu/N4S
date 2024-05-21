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

int main(void)
{
    if (start_simulation() == NULL)
        return 84;
    if (set_speed(0.3) == NULL)
        return 84;
    loop();
    stop_simulation();
    return 0;
}
