#include <stdio.h>
#include "board.h"
#include "input.h"
#include "game.h"

int main(void)
{
    Game g;
    Move m;
    game_init(&g);
    board_print(&g.board);

    while (!game_over(&g)) {
        printf("Player %c's turn. Enter the row and column of the first dot "
               "(e.g., A0 -> 0 0) and second dot: ", g.current);

        MoveStatus s = read_move(&g.board, &m);
        if (s == MOVE_EOF)
            return 0;
        if (s != MOVE_OK) {
            printf("%s\n", move_status_msg(s));
            continue;
        }

        game_apply_move(&g, &m);
        game_print_scores(&g);
        board_print(&g.board);
    }

    game_print_result(&g);
    return 0;
}
