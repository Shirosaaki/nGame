/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "my.h"

int prob_new_salle = 9855;
int prob_one_salle = 6000;
int prob_two_salle = 9000;
int prob_three_salle = 10000;

struct s_room *create_room(int *id, struct s_room *prev)
{
    struct s_room *room = malloc(sizeof(struct s_room));

    room->id = *id;
    room->next1 = NULL;
    room->next2 = NULL;
    room->next3 = NULL;
    room->prev = prev;
    *id += 1;
    return room;
}

int get_nb_of_doors(struct s_room *room)
{
    int nb_of_doors = 0;

    if (room->next1 != NULL) nb_of_doors += 1;
    if (room->next2 != NULL) nb_of_doors += 1;
    if (room->next3 != NULL) nb_of_doors += 1;
    return nb_of_doors;
}

void create_map(t_room *room, int *id, int depth)
{
    if (depth > 10) return;

    int prob = rand() % 10000;

    room->depth = depth;
    if (prob < prob_new_salle) {
        if (prob < prob_one_salle) {
            room->next1 = create_room(id, room);
            create_map(room->next1, id, depth + 1);
        } else if (prob < prob_two_salle) {
            room->next1 = create_room(id, room);
            room->next2 = create_room(id, room);
            create_map(room->next1, id, depth + 1);
            create_map(room->next2, id, depth + 1);
        } else if (prob < prob_three_salle) {
            room->next1 = create_room(id, room);
            room->next2 = create_room(id, room);
            room->next3 = create_room(id, room);
            create_map(room->next1, id, depth + 1);
            create_map(room->next2, id, depth + 1);
            create_map(room->next3, id, depth + 1);
        }
    }
}

int main(void)
{   
    int prob;
    int id = 0;
    int x = 9;
    int y = 8;
    char c;
    t_room *room = create_room(&id, NULL);
    t_room *tmp = room;

    srand(time(NULL));
    create_map(room, &id, 0);
    n_init(1, 0);
    gen_all_rooms(room, 0);
    print_rooms(room, 0);
    while (1) {
        clear();
        main_loop(c, &x, &y, &room);
        c = getch();
        if (c == 'q')
            break;
    }
    endwin();
    return 0;
}