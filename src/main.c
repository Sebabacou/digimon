/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "struct.h"

void my_button(sfRenderWindow *w, sfEvent event, num_t *num)
{
    sfSound *change = sfSound_create();
    sfSoundBuffer *buff2 = sfSoundBuffer_createFromFile("ressources/switch_pokemon.ogg");
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w);
    
    sfSound_setBuffer(change, buff2);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(w);
    if (mouse.x >= 250 && mouse.x <= 276 && mouse.y >= 350 && mouse.y <= 370)
        if (event.type == sfEvtMouseButtonPressed) {
            printf("next\n");
            sfSound_play(change);
        }
    if (mouse.x >= 390 && mouse.x <= 421 && mouse.y >= 326 && mouse.y <= 352)
        if (event.type == sfEvtMouseButtonPressed) {
            printf("next\n");
            sfSound_play(change);
        }
    if (mouse.x >= 206 && mouse.x <= 232 && mouse.y >= 350 && mouse.y <= 370)
        if (event.type == sfEvtMouseButtonPressed) {
            printf("prev\n");
            sfSound_play(change);
        }
    if (mouse.x >= 424 && mouse.x <= 450 && mouse.y >= 326 && mouse.y <= 352)
        if (event.type == sfEvtMouseButtonPressed) {
            printf("prev\n");
            sfSound_play(change);
        }
    research(&event, num);
    sfSound_destroy(change);
}

void end(num_t *num)
{
    sfText_destroy(num->text);
    free(num->str);
    free(num);
}

int main(void)
{
    sfVideoMode m = {620, 449, 32};
    sfRenderWindow *w;
    sfTexture *background = sfTexture_createFromFile("ressources/pokedex.jpg", NULL);
    sfSprite *s = sfSprite_create();
    sfEvent event;
    sfSound *open = sfSound_create();
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile("ressources/open_sound.ogg");
    num_t *num = malloc(sizeof(num_t));

    init_string(num);
    sfSound_setBuffer(open, buff);
    w = sfRenderWindow_create(m, "screen", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    sfSound_play(open);
    while (sfRenderWindow_isOpen(w)) {
        sfSprite_setTexture(s, background, sfTrue);
        sfRenderWindow_drawSprite(w, s, NULL);
        while (sfRenderWindow_pollEvent(w, &event))
            my_button(w, event, num);
        sfRenderWindow_drawText(w, num->text, NULL);
        sfRenderWindow_display(w);
    }
    sfSound_destroy(open);
    sfRenderWindow_destroy(w);
    end(num);
}
