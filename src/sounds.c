/*
** EPITECH PROJECT, 2023
** sounds.c
** File description:
** sounds
*/

#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include <stdio.h>

static char *our_getline(char *src, int *offset, char *dest)
{
    int y = 0;

    for (int i = offset[0]; src[i] != '\n'; i++) {
        dest[y] = src[i];
        offset[0]++;
        y++;
    }
    offset[0]++;
    dest[y] = '\0';
    return dest;
}

void create_sounds(pokesounds_t *sounds)
{
    int offset[1] = {0};
    int fd = open("ressources/song_pokemon.txt", O_RDONLY);
    char *str = malloc(sizeof(char) * 3474);
    char *dest = malloc(sizeof(char) * 30);

    read(fd, str, 3473);
    for (int i = 0; i < 151; i ++) {
        our_getline(str, offset, dest);
        sounds[i].sound = sfMusic_createFromFile(dest);
    }
    return;
}
