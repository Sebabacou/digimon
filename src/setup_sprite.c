/*
** EPITECH PROJECT, 2023
** setup sprite
** File description:
** setup sprite
*/

#include <SFML/Graphics.h>
#include "struct.h"

struct sprt_s setup_bubble(struct sprt_s bbl)
{
    bbl.sprite = sfSprite_create();
    bbl.path = "ressources/bubble.png";
    bbl.texture = sfTexture_createFromFile(bbl.path, NULL);

    bbl.rect.top = bbl.step * bbl.y;
    bbl.rect.left = bbl.step * bbl.x;
    bbl.rect.width = 128;
    bbl.rect.height = 128;

    bbl.pos.x = 42;
    bbl.pos.y = 20;
    bbl.size.x = 0.33;
    bbl.size.y = 0.33;

    sfSprite_setScale(bbl.sprite, bbl.size);
    sfSprite_setPosition(bbl.sprite, bbl.pos);

    return bbl;
}

struct sprt_s setup_sprite(struct sprt_s pkmn)
{
    pkmn.sprite = sfSprite_create();
    pkmn.path = "ressources/anim.png";
    pkmn.texture = sfTexture_createFromFile(pkmn.path, NULL);

    pkmn.rect.top = 5 + (pkmn.step + pkmn.cont) * pkmn.y;
    pkmn.rect.left = 5 + ((pkmn.cont + pkmn.step) * 2) * pkmn.x;
    pkmn.rect.width = pkmn.step;
    pkmn.rect.height = pkmn.step;

    pkmn.pos.x = 90;
    pkmn.pos.y = 132;
    pkmn.size.x = 2;
    pkmn.size.y = 2;
    pkmn.base = pkmn.rect.left;

    sfSprite_setScale(pkmn.sprite, pkmn.size);
    sfSprite_setPosition(pkmn.sprite, pkmn.pos);

    return pkmn;
}

struct sprt_s define_bubble(struct sprt_s bbl)
{
    bbl.x = 0;
    bbl.y = 0;
    bbl.n -= 1;

    for (int f = 0; f < bbl.n; f++) {
        bbl.x++;
        if (bbl.x == 12) {
            bbl.y++;
            bbl.x = 0;
        }
    }

    return bbl;
}

struct sprt_s define_sprite(struct sprt_s pkmn)
{
    pkmn.x = 0;
    pkmn.y = 0;
    pkmn.n -= 1;

    for (int f = 0; f < pkmn.n; f++) {
        pkmn.x++;
        if (pkmn.x == 5) {
            pkmn.y++;
            pkmn.x = 0;
        }
    }

    return pkmn;
}

void init_sprite(sfRenderWindow *window,sfSprite *s, pokemon_t *poke, sfEvent event)
{
    struct sprt_s pkmn;
    struct sprt_s bbl;
    pkmn.n = 150;
    bbl.n = pkmn.n;
    pkmn.cont = 5;
    pkmn.step = 64;
    bbl.step = 128;
    pkmn = define_sprite(pkmn);
    bbl = define_bubble(bbl);
    pkmn = setup_sprite(pkmn);
    bbl = setup_bubble(bbl);

    sfSprite_setTexture(pkmn.sprite, pkmn.texture, sfTrue);
    sfSprite_setTexture(bbl.sprite, bbl.texture, sfTrue);
    sfSprite_setTextureRect(pkmn.sprite, pkmn.rect);
    sfSprite_setTextureRect(bbl.sprite, bbl.rect);
    main_bis(event, window, pkmn, bbl, s, poke);
    sfSprite_destroy(pkmn.sprite);
    sfSprite_destroy(bbl.sprite);
    sfTexture_destroy(pkmn.texture);
    sfTexture_destroy(bbl.texture);
}
