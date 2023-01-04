/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"

void my_button(sfRenderWindow *w, sfEvent event)
{
    
    sfVector2i mouse = sfMouse_getPosition(w);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(w);
    if (mouse.x >= 250 && mouse.x <= 276 && mouse.y >= 350 && mouse.y <= 370)
        if (event.type == sfEvtMouseButtonPressed)
            printf("next\n");
    if (mouse.x >= 390 && mouse.x <= 421 && mouse.y >= 326 && mouse.y <= 352)
        if (event.type == sfEvtMouseButtonPressed)
            printf("next\n");
    if (mouse.x >= 206 && mouse.x <= 232 && mouse.y >= 350 && mouse.y <= 370)
        if (event.type == sfEvtMouseButtonPressed)
            printf("prev\n");
    if (mouse.x >= 424 && mouse.x <= 450 && mouse.y >= 326 && mouse.y <= 352)
        if (event.type == sfEvtMouseButtonPressed)
            printf("prev\n");
}

int main(void)
{
    sfVideoMode m = {620, 449, 32};
    sfRenderWindow *w;
    sfTexture *background = sfTexture_createFromFile("pokedex.jpg", NULL);
    sfSprite *s = sfSprite_create();
    sfEvent event;

    w = sfRenderWindow_create(m, "screen", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    while (sfRenderWindow_isOpen(w)) {
        sfSprite_setTexture(s, background, sfTrue);
        sfRenderWindow_drawSprite(w, s, NULL);
        while (sfRenderWindow_pollEvent(w, &event))
            my_button(w, event);
        sfRenderWindow_display(w);
    }
    sfRenderWindow_destroy(w);
}
