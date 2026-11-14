#ifndef GAME_H
#define GAME_H

#include "board.h"

typedef struct {
    Board board;
    char  current;        /* 'A' or 'B' */
    int   score_a;
    int   score_b;
    int   boxes_claimed;
} Game;

void game_init(Game *g);
int  game_apply_move(Game *g, const Move *m);  /* returns boxes completed */
int  game_over(const Game *g);

#endif
