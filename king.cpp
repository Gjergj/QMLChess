#include "king.h"

bool King::CanMove(const Move &CurrentMove, Piece* board[8][8]){
    int rowDelta = CurrentMove.getToRow() - CurrentMove.getFromRow();
    int colDelta = CurrentMove.getToColumn() - CurrentMove.getFromColumn();
    if (((rowDelta >= -1) && (rowDelta <= 1)) &&
        ((colDelta >= -1) && (colDelta <= 1)))
    {
        return true;
    }
    return false;
}
