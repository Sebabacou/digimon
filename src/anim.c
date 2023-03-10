/*
** EPITECH PROJECT, 2023
** anim
** File description:
** anim
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "struct.h"

void anim(sfRenderWindow* window, struct sprt_s *pk, struct clock_s cl)
{

    cl.time = sfClock_getElapsedTime(cl.clock);
    cl.pasttime = sfTime_asMilliseconds(cl.time);

    if (cl.pasttime >= 500) {
        pk->rect.left += 69;
        if (pk->rect.left > pk->base + 69)
            pk->rect.left = pk->base;
        sfClock_restart(cl.clock);
    }
    sfSprite_setTexture(pk->sprite, pk->texture, sfTrue);
    sfSprite_setTextureRect(pk->sprite, pk->rect);
    sfRenderWindow_drawSprite(window, pk->sprite, NULL);
}
