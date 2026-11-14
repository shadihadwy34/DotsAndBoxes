#include <stdio.h>
#include <stdlib.h>
#include "input.h"

MoveStatus parse_move(const char *line, const Board *b, Move *m)
{
    int r1, c1, r2, c2, used = 0;

    if (sscanf(line, "%d %d %d %d %n", &r1, &c1, &r2, &c2, &used) != 4
        || line[used] != '\0')
        return MOVE_BAD_FORMAT;

    if (r1 < 0 || r1 >= DOT_ROWS || r2 < 0 || r2 >= DOT_ROWS ||
        c1 < 0 || c1 >= DOT_COLS || c2 < 0 || c2 >= DOT_COLS)
        return MOVE_OUT_OF_RANGE;

    if (r1 == r2 && abs(c1 - c2) == 1) {
        m->type = LINE_H;
        m->r = r1;
        m->c = (c1 < c2) ? c1 : c2;
    } else if (c1 == c2 && abs(r1 - r2) == 1) {
        m->type = LINE_V;
        m->r = (r1 < r2) ? r1 : r2;
        m->c = c1;
    } else {
        return MOVE_NOT_ADJACENT;
    }

    if (board_line_taken(b, m))
        return MOVE_TAKEN;

    return MOVE_OK;
}

MoveStatus read_move(const Board *b, Move *m)
{
    char buf[128];

    if (fgets(buf, sizeof buf, stdin) == NULL)
        return MOVE_EOF;

    return parse_move(buf, b, m);
}

const char *move_status_msg(MoveStatus s)
{
    switch (s) {
    case MOVE_BAD_FORMAT:   return "Invalid input. Enter four numbers: r1 c1 r2 c2.";
    case MOVE_OUT_OF_RANGE: return "Dot out of range. Rows are 0-4, columns are 0-5.";
    case MOVE_NOT_ADJACENT: return "Dots must be adjacent (same row or same column, one step apart).";
    case MOVE_TAKEN:        return "That line is already drawn.";
    default:                return "";
    }
}
