/*
** EPITECH PROJECT, 2024
** print
** File description:
** print
*/
#include "my.h"

void print_room(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            printw("%c", map[i][j]);
        }
        printw("\n");
    }
}

void print_rooms(t_room *room, int depth)
{
    if (!room) return;

    for (int i = 0; i < depth; i++) {
        if (i == depth - 1)
            dprintf(2, "|__ ");
        else
            dprintf(2, "|   ");
    }
    dprintf(2, "Room %d (Doors: %d) (Where: %d)\n", room->id, get_nb_of_doors(room), room->entry);
    if (room->next1) print_rooms(room->next1, depth + 1);
    if (room->next2) print_rooms(room->next2, depth + 1);
    if (room->next3) print_rooms(room->next3, depth + 1);
}


void print_room_with_id(t_room *room, int id)
{
    if (!room) return;

    if (room->id == id) {
        print_room(room->map);
        return;
    }
    if (room->next1) print_room_with_id(room->next1, id);
    if (room->next2) print_room_with_id(room->next2, id);
    if (room->next3) print_room_with_id(room->next3, id);
}
