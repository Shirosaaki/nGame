/*
** EPITECH PROJECT, 2024
** gen
** File description:
** gen
*/
#include "my.h"

void gen_all_rooms(t_room *room, int orientation)
{
    if (!room) return;
    int n = get_nb_of_doors(room);

    room->entry = orientation;
    generate_room(room, orientation);
    if (orientation == 1) {
        if (n == 1) {
            if (room->next1) gen_all_rooms(room->next1, 1);
        } else if (n == 2) {
            if (room->next1) gen_all_rooms(room->next1, 0);
            if (room->next2) gen_all_rooms(room->next2, 2);
        } else if (n == 3) {
            if (room->next1) gen_all_rooms(room->next1, 0);
            if (room->next2) gen_all_rooms(room->next2, 1);
            if (room->next3) gen_all_rooms(room->next3, 2);
        }
    } else if (orientation == 2) {
        if (n == 1) {
            if (room->next1) gen_all_rooms(room->next1, 2);
        } else if (n == 2) {
            if (room->next1) gen_all_rooms(room->next1, 1);
            if (room->next2) gen_all_rooms(room->next2, 3);
        } else if (n == 3) {
            if (room->next1) gen_all_rooms(room->next1, 1);
            if (room->next2) gen_all_rooms(room->next2, 2);
            if (room->next3) gen_all_rooms(room->next3, 3);
        }
    } else if (orientation == 3) {
        if (n == 1) {
            if (room->next1) gen_all_rooms(room->next1, 3);
        } else if (n == 2) {
            if (room->next1) gen_all_rooms(room->next1, 2);
            if (room->next2) gen_all_rooms(room->next2, 0);
        } else if (n == 3) {
            if (room->next1) gen_all_rooms(room->next1, 2);
            if (room->next2) gen_all_rooms(room->next2, 3);
            if (room->next3) gen_all_rooms(room->next3, 0);
        }
    } else {
        if (n == 1) {
            if (room->next1) gen_all_rooms(room->next1, 0);
        } else if (n == 2) {
            if (room->next1) gen_all_rooms(room->next1, 3);
            if (room->next2) gen_all_rooms(room->next2, 1);
        } else if (n == 3) {
            if (room->next1) gen_all_rooms(room->next1, 3);
            if (room->next2) gen_all_rooms(room->next2, 0);
            if (room->next3) gen_all_rooms(room->next3, 1);
        };
    }
}
