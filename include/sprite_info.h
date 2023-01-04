/*
** EPITECH PROJECT, 2023
** sprite info
** File description:
** sprite info
*/

#ifndef _SPRITE_INFO_H__
    #define _SPRITE_INFO_H__

    #include <SFML/Graphics.h>

    struct clock_s {
        sfClock *clock;
        sfTime time;
        sfInt32 pasttime;
    };

    struct sprt_s {
        sfSprite * sprite;
        sfTexture *texture;
        char *path;
        sfIntRect rect;
        sfVector2f pos;
        sfVector2f size;
        int base;
        int cont;
        int step;
        int x;
        int y;
        int n;
    };

#endif
