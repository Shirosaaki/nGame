/*
** EPITECH PROJECT, 2024
** my
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <ncurses.h>

typedef struct s_room {
    int id;
    int depth;
    int entry;
    char **map;
    struct s_room *prev;
    struct s_room *next1;
    struct s_room *next2;
    struct s_room *next3;
} t_room;

struct s_room *create_room(int *id, struct s_room *prev);
int get_nb_of_doors(struct s_room *room);
void create_map(t_room *room, int *id, int depth);
void print_rooms(t_room *room, int depth);
void n_init(int color, int cursor);
void n_create_color(int n, int color1, int color2);
void n_active_color(int n);
void n_desactive_color(int n);
void n_print_with_color(char *str, int color);
void n_print_with_color_at(char *str, int color, int x, int y);
char *n_getline(char *str, int size);
void generate_room(t_room *room, int where);
void print_room(char **map);
void print_rooms(t_room *room, int depth);
void gen_all_rooms(t_room *room, int orientation);
void print_room_with_id(t_room *room, int id);
void main_loop(int c, int *x, int *y, t_room **room);

#endif /* !MY_H_ */
