/*
** EPITECH PROJECT, 2022
** pokedex
** File description:
** pokedex
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"

void init_string(num_t *num)
{
    sfFont *font = sfFont_createFromFile("ressources/AldotheApache.ttf");
    num->text = sfText_create();
    sfText_setPosition(num->text, create_vector(95, 365));
    sfText_setColor(num->text, sfGreen);
    sfText_setCharacterSize(num->text, 40);
    sfText_setFont(num->text, font);

    num->str = malloc(sizeof(char) * 4);
    num->value = 0;
    num->str[0] = '\0';
    num->str[1] = '\0';
    num->str[2] = '\0';
}

void is_num_pressed(sfEvent *event, num_t *num)
{
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum1))
        update_number(num, 1);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum2))
        update_number(num, 2);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum3))
        update_number(num, 3);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum4))
        update_number(num, 4);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum5))
        update_number(num, 5);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum6))
        update_number(num, 6);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum7))
        update_number(num, 7);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum8))
        update_number(num, 8);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum9))
        update_number(num, 9);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyNum0))
        update_number(num, 0);
}

void research(sfEvent *event, num_t *num, int *nb, struct sprt_s *pk)
{
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyDelete))
        del_str(num);
    if (num->value > 151)
        return;
    else
        is_num_pressed(event, num);
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyReturn))
        if (num->value != 0) {
            nb[0] = num->value;
            pk->n = nb[0];

            define_sprite(pk);
            setup_sprite(pk);
            reset_str(num);
        }
}
