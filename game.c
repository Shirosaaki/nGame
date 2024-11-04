/*
** EPITECH PROJECT, 2024
** game
** File description:
** game
*/
#include "my.h"

int can_move(int c, int x, int y, t_room *room)
{
    char car;

    if (c == 65 && y > 0) {
        car = room->map[y - 1][x];
        if (car == ' ') return 1;
    } else if (c == 66 && y < 9) {
        car = room->map[y + 1][x];
        if (car == ' ') return 2;
    } else if (c == 67 && x < 19) {
        car = room->map[y][x + 1];
        if (car == ' ') return 3;
    } else if (c == 68 && x > 0) {
        car = room->map[y][x - 1];
        if (car == ' ') return 4;
    }
    return 0;
}

void get_changed_room(t_room **room, int *x, int *y)
{
    int n = get_nb_of_doors(*room);

    if (((*x == 0 && *y == 4) || (*x == 0 && *y == 5)) && (*room)->entry == 1) {
        if (!(*room)->prev) return;
        (*room) = (*room)->prev;
        *x = 18;
    } else if (((*x == 19 && *y == 4) || (*x == 19 && *y == 5)) && (*room)->entry == 3) {
        if (!(*room)->prev) return;
        (*room) = (*room)->prev;
        *x = 1;
    } else if ((*x >= 8 && *x <= 11) && *y == 9 && (*room)->entry == 0) {
        if (!(*room)->prev) return;
        (*room) = (*room)->prev;
        *y = 1;
    } else if ((*x >= 8 && *x <= 11) && *y == 0 && (*room)->entry == 2) {
        if (!(*room)->prev) return;
        (*room) = (*room)->prev;
        *y = 8;
    } else if (n == 1) {
        if (*x == 0 && (*y == 4 || *y == 5) && (*room)->next1 && (*room)->entry == 3) {
            (*room) = (*room)->next1;
            *x = 18;
        } else if (*x == 19 && (*y == 4 || *y == 5) && (*room)->next1 && (*room)->entry == 1) {
            (*room) = (*room)->next1;
            *x = 1;
        } else if ((*x >= 8 && *x <= 11) && *y == 0 && (*room)->next1 && (*room)->entry == 0) {
            (*room) = (*room)->next1;
            *y = 8;
        } else if ((*x >= 8 && *x <= 11) && *y == 9 && (*room)->next1 && (*room)->entry == 2) {
            (*room) = (*room)->next1;
            *y = 1;
        }
    } else if (n == 2) {
        if ((*x >= 8 && *x <= 11) && *y == 9 && (*room)->next1 && (*room)->entry == 3) {
            (*room) = (*room)->next1;
            *y = 1;
        } else if ((*x >= 8 && *x <= 11) && *y == 0 && (*room)->next1 && (*room)->entry == 1) {
            (*room) = (*room)->next1;
            *y = 8;
        } else if (*x == 19 && (*y == 4 || *y == 5) && (*room)->next1 && (*room)->entry == 2) {
            (*room) = (*room)->next1;
            *x = 1;
        } else if (*x == 0 && (*y == 4 || *y == 5) && (*room)->next1 && (*room)->entry == 0) {
            (*room) = (*room)->next1;
            *x = 18;
        }
        if ((*x >= 8 && *x <= 11) && *y == 9 && (*room)->next2 && (*room)->entry == 1) {
            (*room) = (*room)->next2;
            *y = 1;
        } else if ((*x >= 8 && *x <= 11) && *y == 0 && (*room)->next2 && (*room)->entry == 3) {
            (*room) = (*room)->next2;
            *y = 8;
        } else if (*x == 19 && (*y == 4 || *y == 5) && (*room)->next2 && (*room)->entry == 0) {
            (*room) = (*room)->next2;
            *x = 1;
        } else if (*x == 0 && (*y == 4 || *y == 5) && (*room)->next2 && (*room)->entry == 2) {
            (*room) = (*room)->next2;
            *x = 18;
        }
    } else if (n == 3) {
        if ((*x >= 8 && *x <= 11) && *y == 9 && (*room)->next1 && (*room)->entry == 3) {
            (*room) = (*room)->next1;
            *y = 1;
        } else if ((*x >= 8 && *x <= 11) && *y == 0 && (*room)->next1 && (*room)->entry == 1) {
            (*room) = (*room)->next1;
            *y = 8;
        } else if (*x == 19 && (*y == 4 || *y == 5) && (*room)->next1 && (*room)->entry == 2) {
            (*room) = (*room)->next1;
            *x = 1;
        } else if (*x == 0 && (*y == 4 || *y == 5) && (*room)->next1 && (*room)->entry == 0) {
            (*room) = (*room)->next1;
            *x = 18;
        }
        if ((*x >= 8 && *x <= 11) && *y == 9 && (*room)->next2 && (*room)->entry == 2) {
            (*room) = (*room)->next2;
            *y = 1;
        } else if ((*x >= 8 && *x <= 11) && *y == 0 && (*room)->next2 && (*room)->entry == 0) {
            (*room) = (*room)->next2;
            *y = 8;
        } else if (*x == 19 && (*y == 4 || *y == 5) && (*room)->next2 && (*room)->entry == 1) {
            (*room) = (*room)->next2;
            *x = 1;
        } else if (*x == 0 && (*y == 4 || *y == 5) && (*room)->next2 && (*room)->entry == 3) {
            (*room) = (*room)->next2;
            *x = 18;
        }
        if ((*x >= 8 && *x <= 11) && *y == 9 && (*room)->next3 && (*room)->entry == 1) {
            (*room) = (*room)->next3;
            *y = 1;
        } else if ((*x >= 8 && *x <= 11) && *y == 0 && (*room)->next3 && (*room)->entry == 3) {
            (*room) = (*room)->next3;
            *y = 8;
        } else if (*x == 19 && (*y == 4 || *y == 5) && (*room)->next3 && (*room)->entry == 0) {
            (*room) = (*room)->next3;
            *x = 1;
        } else if (*x == 0 && (*y == 4 || *y == 5) && (*room)->next3 && (*room)->entry == 2) {
            (*room) = (*room)->next3;
            *x = 18;
        }
    }
}

void main_loop(int c, int *x, int *y, t_room **room)
{
    char move = can_move(c, *x, *y, *room);

    if (move == 1) *y -= 1;
    if (move == 2) *y += 1;
    if (move == 3) *x += 1;
    if (move == 4) *x -= 1;
    get_changed_room(room, x, y);
    print_room((*room)->map);
    n_print_with_color_at("X", 1, *x, *y);
    refresh();
}