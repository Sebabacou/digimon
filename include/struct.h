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

} struct_timer;

typedef struct num_s {
    
    sfText *text;
    int value;
    char *str;

} num_t;

typedef struct pokesounds_s {

    sfMusic *sound;
    
} pokesounds_t;

sfVector2f create_vector(int x, int y);
void int_to_string(int n, char *str);
void update_number(num_t *num, int nb);
void del_str(num_t *num);
void reset_str(num_t *num);
void research(sfEvent *event, num_t *num);
void init_string(num_t *num);
void create_sounds(pokesounds_t *sounds);

#endif
