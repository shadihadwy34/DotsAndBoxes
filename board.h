#ifndef BOARD_H
#define BOARD_H

#define DOT_ROWS 5
#define DOT_COLS 6
#define BOX_ROWS (DOT_ROWS - 1)
#define BOX_COLS (DOT_COLS - 1)


typedef struct{
    int hline[DOT_ROWS][BOX_COLS];
    int vline[BOX_ROWS][DOT_COLS];
    char owner[BOX_ROWS][BOX_COLS];
}Board;

void board_init(Board *b);
void board_print(const Board*b);

#endif
