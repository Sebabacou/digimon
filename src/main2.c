/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/header.h"

void analyse_events(sfRenderWindow* w, sfEvent event, num_t *num, sfSound *change)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w);

    while (sfRenderWindow_pollEvent(w, &event)) {
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
}

void display_window(sfRenderWindow* window, struct sprt_s pkmn, struct sprt_s bbl)
{
    struct clock_s cl;
    sfEvent event;
    sfSprite *s = sfSprite_create();
    sfTexture *background = sfTexture_createFromFile("ressources/pokedex.jpg", NULL);
    sfSprite_setTexture(s, background, sfTrue);

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
    
    cl.clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, s, NULL);
        sfRenderWindow_drawText(window, num->text, NULL);
        sfRenderWindow_drawSprite(window, pkmn.sprite, NULL);
        sfRenderWindow_drawSprite(window, bbl.sprite, NULL);
        pkmn = anim(window, pkmn, cl);
	sfRenderWindow_display(window);
        analyse_events(window, event, num, change);
    }
    sfSprite_destroy(s);
    sfTexture_destroy(background);
    sfText_destroy(num->text);
    free(num->str);
    free(num);
    sfSound_destroy(open);
    sfSound_destroy(change);
}

int main(int argc, char **argv)
{
    sfRenderWindow* window;
    sfVideoMode mode = {620, 449, 32};

    if (argc == 1) {
        window = sfRenderWindow_create
            (mode, "PKDX", sfResize | sfClose, NULL);
	if (!window)
            return 84;
        init_sprite(window);
        sfRenderWindow_destroy(window);
    }
     return 0;
}
