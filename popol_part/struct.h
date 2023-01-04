/*
** EPITECH PROJECT, 2023
** struct
** File description:
** time struct and button
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef MY_STRUCT_
    #define MY_STRUCT_

typedef struct timer {
    sfClock *clock;
    sfTime time;
}struct_timer;

#endif
