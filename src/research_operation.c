/*
** EPITECH PROJECT, 2022
** research lib
** File description:
** pokedex
*/
#include <SFML/Graphics.h>
#include "struct.h"

void reset_str(num_t *num)
{
    num->value = 0;
    num->str[0] = '\0';
    num->str[1] = '\0';
    num->str[2] = '\0';
    sfText_setString(num->text, num->str);
}

void del_str(num_t *num)
{
    num->value /= 10;
    if (num->value < 10) {
        num->str[1] = '\0';
        num->str[2] = '\0';
    }
    if (num->value < 100 && num->value > 9)
        num->str[2] = '\0';
    int_to_string(num->value, num->str);
    if (num->value == 0)
        num->str[0] = '\0';
    sfText_setString(num->text, num->str);
    sfText_setColor(num->text, sfGreen);
}

void update_number(num_t *num, int nb)
{
    if (num->value <= 100)
        num->value = num->value * 10 + nb;
    else
        return;
    if (num->value > 151)
        sfText_setColor(num->text, sfRed);
    int_to_string(num->value, num->str);
    sfText_setString(num->text, num->str);
    if (num->value <= 151)
        sfText_setColor(num->text, sfGreen);
}
