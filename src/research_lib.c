/*
** EPITECH PROJECT, 2022
** research lib
** File description:
** pokedex
*/
#include <SFML/Graphics.h>
#include "struct.h"

sfVector2f create_vector(int x, int y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return position;
}

int getsize(int value)
{
    int len = 1;

    for (int n_copy = value; n_copy >= 10; n_copy /= 10) {
        len += 1;
    }
    return len;
}

void int_to_string(int n, char *str)
{
    int len = 1;

    for (int n_copy = n; n_copy >= 10; n_copy /= 10) {
        len = len * 10;
    }
    for (int i = 0; len > 0; len /= 10) {
        if (i > 4)
            break;
        str[i] = (n / len + 48);
        n -= n / len * len;
        i++;
    }
}
