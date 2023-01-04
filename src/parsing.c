#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int nb_return_scanner(char *str, char limiter)
{
    int x = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == limiter) {
            x++;
        }
    }
    return x;
}

int search_index(char *str, char limiter)
{
    int x = 0;
    while (str[x] != '\0') {
        if (str[x] == limiter) {
            return x;
        }
        x++;
    }
    return -1;
}


char *my_ndup(char *str, int n)
{
    int i = 0;
    char *dup = malloc(sizeof(char) * n + 1);
    while (i != n && str[i] != '\0') {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char **my_str_to_word_array(char *str, char limiter)
{
    int a = nb_return_scanner(str, limiter);
    int index = 0;
    int x = 0;
    int i = 0;
    char **arr = malloc(sizeof(char *) * (a + 1));
    for (; str[i] != '\0'; i++);
    if (str == NULL || arr == NULL)
        return NULL;
    for (; str[x] != '\0'; x++) {
        index = search_index(str, limiter);
        if (index == -1 || index == 0) {
            arr[x++] = strdup(str);
            break;
        }
        arr[x] = my_ndup(str, index);
        str += index + 1;
    }
    arr[x] = NULL;
    return arr;
}

int count_1(void)
{
    FILE *fp = fopen("pokemon.csv", "r");
    int count0 = 0;
    char *line = NULL;
    size_t len = 0;
    int read = 0;

    if (fp == NULL)
        return -1;
    for (int i = 0; (read = getline(&line, &len, fp)) != -1; i++) {
        count0++;
    }
    return count0;
}

int poke_sort(pokemon_t *poke, int k, char **bufer)
{
    char **arr = my_str_to_word_array(bufer[k], ';');
    
    poke[k].id = atoi(arr[0]);
    poke[k].name = malloc(sizeof(char) * 100);
    poke[k].japanese_name = malloc(sizeof(char) * 100);
    poke[k].type1 = malloc(sizeof(char) * 100);
    poke[k].type2 = malloc(sizeof(char) * 100);
    poke[k].classification = malloc(sizeof(char) * 100);
    poke[k].attack = malloc(sizeof(char) * 100);
    poke[k].defense = malloc(sizeof(char) * 100);
    poke[k].hp = malloc(sizeof(char) * 100);
    poke[k].sp_attack = malloc(sizeof(char) * 100);
    poke[k].sp_defense = malloc(sizeof(char) * 100);
    poke[k].speed = malloc(sizeof(char) * 100);
    poke[k].weight_kg = malloc(sizeof(char) * 100);
    poke[k].height_m = malloc(sizeof(char) * 100);
    poke[k].generation = malloc(sizeof(char) * 100);
    poke[k].is_legendary = malloc(sizeof(char) * 100);
    poke[k].name = arr[1];
    poke[k].japanese_name = arr[2];
    poke[k].type1 = arr[3];
    poke[k].type2 = arr[4];
    poke[k].classification = arr[5];
    poke[k].attack = arr[6];
    poke[k].defense = arr[7];
    poke[k].hp = arr[8];
    poke[k].sp_attack = arr[9];
    poke[k].sp_defense = arr[10];
    poke[k].speed = arr[11];
    poke[k].weight_kg = arr[12];
    poke[k].height_m = arr[13];
    poke[k].generation = arr[14];
    poke[k].is_legendary = arr[15];
    return 0;
}

int parsing(void)
{
    int fd = open("ressources/pokemon.csv", O_RDONLY);
    char **line = malloc(sizeof(char *) * 153);
    char *buffer = malloc(sizeof(char *) * 100001);
    pokemon_t *poke = malloc(sizeof(pokemon_t) * 153);

    read(fd, buffer, 100000);
    for (size_t i = 0;  i < 152; i++) {
        line = my_str_to_word_array(buffer, '\n');
    }
    for(int k = 1; k != 152; k++) {
        poke_sort(poke, k, line);
    }
    return 0;
}
