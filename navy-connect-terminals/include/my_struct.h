/*
** EPITECH PROJECT, 2020
** navu
** File description:
** all variable
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct navy
{

/********** MAPS *******/

    char **map_player;
    char **map_enemy;
    int victory_defeat;
    int pid;
    int enemy_pid;
    int x_attak;
    int y_attak;

/* /\********* BOATS ******\/ */

/*     int size_boat; */
/*     int pos1; */
/*     int pos2; */
/*     int pos3; */
/*     int pos4; */
/*     int idx; */

/* /\********* PLAYS ****\/ */

/*     char *move1; */
/*     char *move2; */
    
/* /\******** SIGNAUX ***\/ */

/*     int PID_1; */
/*     int PID_2; */

/* /\******** VICT/DEF **\/ */
/*     int touch1; */
/*     int touch2; */
/*     int nb_boat1; */
/*     int nb_boat2; */

/*     int player; */
} navy_t;

#endif
