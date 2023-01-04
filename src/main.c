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

void end(num_t *num, sfSound *open, sfSound *change, sfRenderWindow *w)
{
    sfText_destroy(num->text);
    free(num->str);
    free(num);
    sfSound_destroy(open);
    sfSound_destroy(change);
    sfRenderWindow_destroy(w);
}

int main_bis(sfEvent event, sfRenderWindow *w, sfSprite *s)
{
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
    sfSound_play(open);
    while (sfRenderWindow_isOpen(w)) {
        while (sfRenderWindow_pollEvent(w, &event))
            my_button(w, event, num, change);
        sfRenderWindow_drawSprite(w, s, NULL);
        sfRenderWindow_drawText(w, num->text, NULL);
        sfRenderWindow_display(w);
    }
    end(num, open, change, w);
}

int main(void)
{
    sfVideoMode m = {620, 449, 32};
    sfRenderWindow *w = sfRenderWindow_create(m, "screen", sfResize | sfClose, NULL);
    sfTexture *background = sfTexture_createFromFile("ressources/pokedex.jpg", NULL);
    sfSprite *s = sfSprite_create();
    sfEvent event;
    pokemon_t *poke = malloc(sizeof(pokemon_t) * 153);

    parsing(poke);
    sfRenderWindow_setFramerateLimit(w, 60);
    sfSprite_setTexture(s, background, sfTrue);
    main_bis(event, w, s);
    return 0;
}
