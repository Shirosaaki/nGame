/*
** EPITECH PROJECT, 2024
** gen
** File description:
** gen
*/
#include "my.h"

void fill_map_with_char(char **map, int rows, int cols, char ch) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = ch;
        }
        map[i][cols] = '\0';
    }
}

void set_borders(char **map, int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        map[0][i] = '-';
        map[rows - 1][i] = '-';
    }
    for (int i = 0; i < rows; i++) {
        map[i][0] = '|';
        map[i][cols - 1] = '|';
    }
    map[0][0] = map[0][cols - 1] = map[rows - 1][0] = map[rows - 1][cols - 1] = '+';
}

void set_door(char **map, int row, int col_start, int width) {
    for (int i = 0; i < width; i++) {
        if (width == 4)
            map[row][col_start + i] = ' ';
        else
            map[row + i][col_start] = ' ';
    }
}

void place_doors(char **map, int where, int n, int depth) {
    if (where == 0) set_door(map, 9, 8, 4);
    else if (where == 1) set_door(map, 4, 0, 2);
    else if (where == 2) set_door(map, 0, 8, 4);
    else if (where == 3) set_door(map, 4, 19, 2);
    if (depth >= 10) return;

    if (n == 1) {
        if (where == 0) {
            set_door(map, 0, 8, 4);
        } else if (where == 3) {
            set_door(map, 4, 0, 2);
        } else if (where == 2) {
            set_door(map, 9, 8, 4);
        } else if (where == 1) {
            set_door(map, 4, 19, 2);
        }
    } else if (n == 2) {
        if (where == 0 || where == 2) {
            set_door(map, 4, 0, 2);
            set_door(map, 4, 19, 2);
        } else if (where == 1 || where == 3) {
            set_door(map, 0, 8, 4);
            set_door(map, 9, 8, 4);
        }
    } else {
        set_door(map, 4, 0, 2);
        set_door(map, 0, 8, 4);
        set_door(map, 9, 8, 4);
        set_door(map, 4, 19, 2);
    }
}

void generate_room(t_room *room, int where) {
    char **map = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 10; i++) {
        map[i] = malloc(sizeof(char) * 21);
    }
    map[10] = NULL;

    fill_map_with_char(map, 10, 20, ' ');
    set_borders(map, 10, 20);
    place_doors(map, room->entry, get_nb_of_doors(room), room->depth);

    room->map = map;
}
