/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#ifndef _HEADER_H__
    #define _HEADER_H__

    #include "../include/sprite_info.h"
    #include "../include/struct.h"
    #include <SFML/Graphics.h>
    #include <SFML/Config.h>
    #include <SFML/System.h>
    #include <time.h>
    #include <stdlib.h>
    #include <unistd.h>

void init_sprite(sfRenderWindow *window);
struct sprt_s anim(sfRenderWindow* window, struct sprt_s pk, struct clock_s cl);
void display_window(sfRenderWindow* window, struct sprt_s pkmn, struct sprt_s bbl);

#endif
