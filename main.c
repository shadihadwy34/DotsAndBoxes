#include <stdio.h>
#include "board.h"
#include "input.h"

int main(void)
{
    Board b;
    Move m;
    board_init(&b);

    for (;;) {
        board_print(&b);
        printf("Enter the row and column of the first dot and second dot: ");

        MoveStatus s = read_move(&b, &m);
        if (s == MOVE_EOF)
            break;
        if (s != MOVE_OK) {
            printf("%s\n", move_status_msg(s));
            continue;
        }
        board_set_line(&b, &m);
    }
    return 0;
}
