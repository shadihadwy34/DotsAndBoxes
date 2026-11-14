#include "board.h"

int main(void){
    Board b;
    board_init(&b);

    b.hline[0][0] = 1;
    b.hline[1][0] = 1;
    b.vline[0][0] = 1;
    b.vline[0][1] = 1;
    b.owner[0][0] = 'A';

    board_print(&b);
    return 0;

}