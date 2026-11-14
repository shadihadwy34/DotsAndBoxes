#ifndef BOARD_H
#define BOARD_H

#define DOT_ROWS 5
#define DOT_COLS 6
#define BOX_ROWS (DOT_ROWS - 1)
#define BOX_COLS (DOT_COLS - 1)

typedef struct {
    int  hline[DOT_ROWS][BOX_COLS];
    int  vline[BOX_ROWS][DOT_COLS];
    char owner[BOX_ROWS][BOX_COLS];
} Board;

typedef enum { LINE_H, LINE_V } LineType;

typedef struct {
    LineType type;
    int r, c;   /* top-left dot of the line */
} Move;

void board_init(Board *b);
void board_print(const Board *b);
int  board_line_taken(const Board *b, const Move *m);
void board_set_line(Board *b, const Move *m);

#endif
