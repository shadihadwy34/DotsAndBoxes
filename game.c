#include "game.h"

static int box_complete(const Board *b, int r, int c)
{
    return b->hline[r][c] && b->hline[r + 1][c] &&
           b->vline[r][c] && b->vline[r][c + 1];
}

static int try_claim(Game *g, int r, int c)
{
    if (r < 0 || r >= BOX_ROWS || c < 0 || c >= BOX_COLS)
        return 0;
    if (g->board.owner[r][c] != ' ')
        return 0;
    if (!box_complete(&g->board, r, c))
        return 0;

    g->board.owner[r][c] = g->current;
    if (g->current == 'A')
        g->score_a++;
    else
        g->score_b++;
    g->boxes_claimed++;
    return 1;
}

void game_init(Game *g)
{
    board_init(&g->board);
    g->current = 'A';
    g->score_a = 0;
    g->score_b = 0;
    g->boxes_claimed = 0;
}

int game_apply_move(Game *g, const Move *m)
{
    int claimed = 0;

    board_set_line(&g->board, m);

    if (m->type == LINE_H) {
        claimed += try_claim(g, m->r - 1, m->c);  /* box above */
        claimed += try_claim(g, m->r, m->c);      /* box below */
    } else {
        claimed += try_claim(g, m->r, m->c - 1);  /* box on the left */
        claimed += try_claim(g, m->r, m->c);      /* box on the right */
    }

    if (claimed == 0)
        g->current = (g->current == 'A') ? 'B' : 'A';

    return claimed;
}

int game_over(const Game *g)
{
    return g->boxes_claimed == BOX_ROWS * BOX_COLS;
}
