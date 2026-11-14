#include <stdio.h>
#include "board.h"

void board_init(Board *b)
{
    for (int r = 0; r < DOT_ROWS; r++)
        for (int c = 0; c < BOX_COLS; c++)
            b->hline[r][c] = 0;

    for (int r = 0; r < BOX_ROWS; r++)
        for (int c = 0; c < DOT_COLS; c++)
            b->vline[r][c] = 0;

    for (int r = 0; r < BOX_ROWS; r++)
        for (int c = 0; c < BOX_COLS; c++)
            b->owner[r][c] = ' ';
}

void board_print(const Board *b)
{
    printf("  ");
    for (int c = 0; c < DOT_COLS; c++)
        printf("%d ", c);
    printf("\n");

    for (int r = 0; r < DOT_ROWS; r++) {
        printf("%d ", r);
        for (int c = 0; c < DOT_COLS; c++) {
            printf(".");
            if (c < BOX_COLS)
                printf("%c", b->hline[r][c] ? '-' : ' ');
        }
        printf("\n");

        if (r < BOX_ROWS) {
            printf("  ");
            for (int c = 0; c < DOT_COLS; c++) {
                printf("%c", b->vline[r][c] ? '|' : ' ');
                if (c < BOX_COLS)
                    printf("%c", b->owner[r][c]);
            }
            printf("\n");
        }
    }
}

int board_line_taken(const Board *b, const Move *m)
{
    return (m->type == LINE_H) ? b->hline[m->r][m->c]
                               : b->vline[m->r][m->c];
}

void board_set_line(Board *b, const Move *m)
{
    if (m->type == LINE_H)
        b->hline[m->r][m->c] = 1;
    else
        b->vline[m->r][m->c] = 1;
}
