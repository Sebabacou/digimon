/*
** EPITECH PROJECT, 2023
** sounds.c
** File description:
** sounds
*/
static char *getline(char *dest, char *src)
{
    int y = 0;
    for (int i = 0; src[i] != '\n' || src[i] != '\0'; i ++)
        dest[y] = src[i];
    
    return dest;
}

void create_sounds(pokesounds_t *sounds)
{
    int fd = read(
    for (int i = 0; i < 152; i ++) {
        sounds[i]->sound = sfMusic_createFromFile(getline(buffer));
    }
    return;
}
