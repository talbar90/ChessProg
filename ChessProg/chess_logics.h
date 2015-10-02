#ifndef CHESS_LOGICS_
#define CHESS_LOGICS_

#ifndef CHESS_
#include "ChessProg.h"
#endif CHESS_

//#ifndef CHESS_UTILS_
//#include "chess_utils.h"
//#endif CHESS_UTILS_

#include <ctype.h>


extern Move* moves;
extern Move* moves_head;
extern char curr_piece;
extern COLOR curr_player;
extern Move* best_move;
extern COLOR user_color;
extern COLOR next_player; // recently added 
extern int minimax_depth;
extern int game_mode; // 2 player mode
extern int best_depth;
extern int board_count;
extern char black_promotables[4];
extern char white_promotables[4];


#endif CHESS_LOGICS_