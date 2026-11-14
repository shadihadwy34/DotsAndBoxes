#ifndef INPUT_H
#define INPUT_H

#include "board.h"

typedef enum {
    MOVE_OK,
    MOVE_EOF,
    MOVE_BAD_FORMAT,
    MOVE_OUT_OF_RANGE,
    MOVE_NOT_ADJACENT,
    MOVE_TAKEN
} MoveStatus;

MoveStatus parse_move(const char *line, const Board *b, Move *m);
MoveStatus read_move(const Board *b, Move *m);
const char *move_status_msg(MoveStatus s);

#endif
