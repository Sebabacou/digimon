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

void my_button(sfRenderWindow *w, sfEvent event, num_t *num, sfSound *change)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w);
    
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(w);
    if (mouse.x >= 250 && mouse.x <= 276 && mouse.y >= 350 && mouse.y <= 370)
        if (event.type == sfEvtMouseButtonPressed)
            sfSound_play(change);
    if (mouse.x >= 390 && mouse.x <= 421 && mouse.y >= 326 && mouse.y <= 352)
        if (event.type == sfEvtMouseButtonPressed) 
            sfSound_play(change);
    if (mouse.x >= 206 && mouse.x <= 232 && mouse.y >= 350 && mouse.y <= 370)
        if (event.type == sfEvtMouseButtonPressed)
            sfSound_play(change);
    if (mouse.x >= 424 && mouse.x <= 450 && mouse.y >= 326 && mouse.y <= 352)
        if (event.type == sfEvtMouseButtonPressed)
            sfSound_play(change);
    research(&event, num);
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
    sfSound *change = sfSound_create();
    sfSoundBuffer *buff2 = sfSoundBuffer_createFromFile("ressources/switch_pokemon.ogg");
    num_t *num = malloc(sizeof(num_t));
    pokesounds_t *sounds = malloc(sizeof(pokesounds_t) * 151);

    create_sounds(sounds);
    init_string(num);
    sfSound_setBuffer(open, buff);
    sfSound_setBuffer(change, buff2);
    w = sfRenderWindow_create(m, "screen", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    sfSound_play(open);
    while (sfRenderWindow_isOpen(w)) {
        sfSprite_setTexture(s, background, sfTrue);
        sfRenderWindow_drawSprite(w, s, NULL);
        while (sfRenderWindow_pollEvent(w, &event))
            my_button(w, event, num, change);
        sfRenderWindow_drawText(w, num->text, NULL);
        sfRenderWindow_display(w);
    }
    sfSound_destroy(open);
    sfSound_destroy(change);
    sfRenderWindow_destroy(w);
    end(num);
}
