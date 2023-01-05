/*
** EPITECH PROJECT, 2023
** struct
** File description:
** time struct and button
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef MY_STRUCT_
    #define MY_STRUCT_

struct clock_s {
    sfClock *clock;
    sfTime time;
    sfInt32 pasttime;
};

struct sprt_s {
    sfSprite * sprite;
    sfTexture *texture;
    char *path;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f size;
    int base;
    int cont;
    int step;
    int x;
    int y;
    int n;
};

typedef struct timer {

    sfClock *clock;
    sfTime time;

} struct_timer;

typedef struct num_s {
    
    sfText *text;
    int value;
    char *str;

} num_t;

typedef struct pokesounds_s {

    sfMusic *sound;
    
} pokesounds_t;

typedef struct pokemon_s{
    int id;
    char *name;
    char *japanese_name;
    char *type1;
    char *type2;
    char *classification;
    char* attack;
    char* defense;
    char* hp;
    char* sp_attack;
    char* sp_defense;
    char* speed;
    char* weight_kg;
    char* height_m;
    char* generation;
    char* is_legendary;
} pokemon_t;

sfVector2f create_vector(int x, int y);
void int_to_string(int n, char *str);
void update_number(num_t *num, int nb);
void del_str(num_t *num);
void reset_str(num_t *num);
void research(sfEvent *event, num_t *num, int *nb, struct sprt_s *pkmn);
void init_string(num_t *num);
void create_sounds(pokesounds_t *sounds);
int parsing(pokemon_t *);

void anim(sfRenderWindow* window, struct sprt_s *pk, struct clock_s cl);
void init_sprite(sfRenderWindow *window,sfSprite *s, pokemon_t *poke, sfEvent event);
int main_bis(sfEvent event, sfRenderWindow *w,struct sprt_s *pkmn, struct sprt_s bbl, sfSprite *s, pokemon_t *poke);
void define_sprite(struct sprt_s *pkmn);
void setup_sprite(struct sprt_s *pkmn);
struct sprt_s define_bubble(struct sprt_s bbl);
struct sprt_s setup_bubble(struct sprt_s bbl);

#endif
